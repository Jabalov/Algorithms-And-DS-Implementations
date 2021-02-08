using System;
using System.Collections;
using System.Data.HashFunction;

namespace M4CuckooFilter
{
    public class CuckooFilter
    {
        int _maxKicks = 500;
        int _numEntriesPerBucket = 4;
        int _emptyFingerprint = 0;
        int _fingerprintSize;
        int _numBuckets;
        int _bucketMask;
        int _fingerprintMask;
        BitArray _bitStore;
        Random _rnd;
        MurmurHash3 _murmur = new MurmurHash3();
        CityHash _cityHash = new CityHash();

        /// <summary>
        /// Creates a new instance of a cuckoo filter.
        /// Notice, that this is a non-optimized reference implementation only.
        /// It is made, solely for educational purposes
        /// (the Pluralsight course "Using Advanced Data Structures in Modern Applications").
        /// </summary>
        /// <param name="capacity">Max number of items to handle.</param>
        /// <param name="falsePositiveRate">The probability of false positives.</param>
        public CuckooFilter(int capacity, double falsePositiveRate)
        {
            int exp = (int)Math.Ceiling(Math.Log(capacity, 2));
            _numBuckets = 1 << exp; // The closest power of 2 above "capacity"
            _bucketMask = _numBuckets - 1;
            _fingerprintSize = (int)Math.Ceiling(Math.Log(2*_numEntriesPerBucket/falsePositiveRate, 2));
            _fingerprintMask = (1 << _fingerprintSize) - 1;
            _bitStore = new BitArray(_numBuckets * _numEntriesPerBucket * _fingerprintSize);
            _rnd = new Random(41);
        }

        /// <summary>
        /// Adds a key to the cuckoo filter.
        /// </summary>
        /// <param name="key">The key to add.</param>
        /// <returns>True if the insertion suceeded.</returns>
        /// <exception cref="ArgumentException">If the filter is full, and the key cannot be added.</exception>
        public bool Insert(int key)
        {
            var fp = Fingerprint(key);
            var fpHash = Hash(fp);
            int[] buckets = new int[2];
            var keyHash = Hash(key); 
            buckets[0] = keyHash;
            buckets[1] = keyHash ^ fpHash;

            if (TryInsertAtBucket(buckets[0], fp) || TryInsertAtBucket(buckets[1], fp))
                return true;

            var idx = _rnd.Next(2);
            var bucket = buckets[idx];
            for(var i = 0; i < _maxKicks; i++)
            {
                idx = _rnd.Next(_numEntriesPerBucket);
                var bucketFp = GetFingerprint(bucket, idx);
                SetFingerprint(bucket, idx, fp);
                fp = bucketFp;
                fpHash = Hash(fp);
                bucket = bucket ^ fpHash;
                if (TryInsertAtBucket(bucket, fp))
                    return true;
            }
            throw new ArgumentException("Cuckoo filter is full");
        }

        /// <summary>
        /// Queries for existence of the specified key in the cuckoo filter.
        /// </summary>
        /// <param name="key">The key to search for.</param>
        /// <returns>True if the key has been added to the filter with high probability
        /// (false positives may occur). False if the key has never been inserted
        /// (false negatives never occur).</returns>
        public bool Contains(int key)
        {
            var fp = Fingerprint(key);
            var fpHash = Hash(fp);
            int[] buckets = new int[2];
            var keyHash = Hash(key);
            buckets[0] = keyHash;
            buckets[1] = keyHash ^ fpHash;
            if (GetFingerprintIndex(buckets[0], fp) != -1 || GetFingerprintIndex(buckets[1], fp) != -1)
                return true;
            return false;
        }

        /// <summary>
        /// Removes a key from the cuckoo filter.
        /// </summary>
        /// <param name="key">The key to remove.</param>
        /// <returns>True if the key (or the fingerprint of the key) was found in the filter.
        /// False otherwise.</returns>
        public bool Remove(int key)
        {
            var fp = Fingerprint(key);
            var fpHash = Hash(fp);
            int[] buckets = new int[2];
            var keyHash = Hash(key);
            buckets[0] = keyHash;
            buckets[1] = keyHash ^ fpHash;
            for(var i = 0; i < 2; i++)
            {
                var idx = GetFingerprintIndex(buckets[i], fp);
                if (idx != -1)
                {
                    SetFingerprint(buckets[i], idx, _emptyFingerprint);
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// Tries to insert a fingerprint at a free slot in the specified bucket.
        /// </summary>
        /// <param name="bucket">The bucket to search for an empty slot.</param>
        /// <param name="fingerprint">The fingerprint to insert.</param>
        /// <returns>True if insertion succeeded. False otherwise.</returns>
        bool TryInsertAtBucket(int bucket, int fingerprint)
        {
            var idx = GetEmptyIndex(bucket);
            if (idx == -1)
                return false;
            SetFingerprint(bucket, idx, fingerprint);
            return true;
        }

        /// <summary>
        /// Gets the position of the first empty slot for a given bucket. If any.
        /// </summary>
        /// <param name="bucket">The bucket to search.</param>
        /// <returns>The position of the first empty slot. -1 if none are found.</returns>
        int GetEmptyIndex(int bucket)
        {
            for(var i = 0; i < _numEntriesPerBucket; i++)
            {
                var fp = GetFingerprint(bucket, i);
                if (fp == 0)
                    return i;
            }
            return -1;
        }

        int MurMur(int key)
        {
            var h = _murmur.ComputeHash(key);
            return BitConverter.ToInt32(h, 0);
        }

        int CityHash(int key)
        {
            var h = _cityHash.ComputeHash(key);
            return BitConverter.ToInt32(h, 0);
        }

        /// <summary>
        /// General method for hashing a key.
        /// It avoids hashing to 0 in order to not collide with the "empty" bucket slot value,
        /// which is also 0.
        /// </summary>
        /// <param name="key">The key to hash.</param>
        /// <returns>The hash value</returns>
        int Hash(int key)
        {
            var hash = CityHash(key) & _bucketMask; // Consider experimenting with other hash functions...
            if (hash == 0)
                hash++;  // in order to avoid hashing to 0 (because the hash is also used for fingerprints)
            return hash;
        }

        /// <summary>
        /// Generates a fingerprint of the appropriate length from a key.
        /// </summary>
        /// <param name="key">The key to generate a fingerprint of.</param>
        /// <returns>The fingerprint integer.</returns>
        int Fingerprint(int key)
        {
            int fp = key.GetHashCode();
            fp &= _fingerprintMask;
            if (fp == _emptyFingerprint)
                fp++;  // in order to avoid conflicting with _emptyFingerprint
            return fp; 
        }

        /// <summary>
        /// Gets the index of the first occurence, if any, of the specified fingerprint
        /// in the specified bucket.
        /// </summary>
        /// <param name="bucket">The bucket to search in.</param>
        /// <param name="fingerprint">The fingerprint to search for.</param>
        /// <returns>The slot index of the fingerprint, if found. -1 if not found.</returns>
        int GetFingerprintIndex(int bucket, int fingerprint)
        {
            for (var i = 0; i < _numEntriesPerBucket; i++)
            {
                var fp = GetFingerprint(bucket, i);
                if (fp == fingerprint)
                    return i;
            }
            return -1;
        }

        bool BucketContainsFingerprint(int bucket, int fingerprint)
        {
            return GetFingerprintIndex(bucket, fingerprint) != -1;
        }

        int GetFingerprint(int bucket, int index)
        {
            var startIdx = bucket * _fingerprintSize * _numEntriesPerBucket + index * _fingerprintSize;
            int fp = 0;
            for(int i=0; i < _fingerprintSize; i++)
            {
                fp <<= 1;
                fp |= Convert.ToInt32(_bitStore.Get(startIdx + i));
            }
            return fp;
        }

        bool SetFingerprint(int bucket, int index, int fingerprint)
        {
            var startIdx = bucket * _fingerprintSize * _numEntriesPerBucket + index * _fingerprintSize;
            for (int i = _fingerprintSize-1; i >= 0; i--)
            {
                _bitStore.Set(startIdx + i, (fingerprint & 1) == 1);
                fingerprint >>= 1;
            }
            return true;
        }
    }
}
