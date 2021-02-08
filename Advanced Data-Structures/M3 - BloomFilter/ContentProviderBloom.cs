using System;
using System.Data.HashFunction;
using BloomFilterDotNet;

namespace M3BloomFilter
{
    public class ContentProviderBloom : IContentProvider
    {
        IStorage _storage;
        ICache _cache;
        BloomFilter<int> _bloom;
        MurmurHash3 _murmur = new MurmurHash3();

        public ContentProviderBloom(ICache cache, IStorage storage)
        {
            _cache = cache;
            _storage = storage;
            _bloom = new BloomFilter<int>(1500000, 0.01, GetMurMur);
        }

        public int GetMurMur(int key)
        {
            var h = _murmur.ComputeHash(key);
            return BitConverter.ToInt32(h, 0);
        }

        public Media GetContent(int id)
        {
            if (_cache.ContainsKey(id))
                return _cache.Get(id);

            var content = _storage.GetContent(id);

            var probablyFetchedBefore = _bloom.Contains(id);
            if (probablyFetchedBefore)
                _cache.Add(id, content);

            _bloom.Add(id);
            return content;
        }

        public void RemoveContent(int id)
        {
            _storage.RemoveContent(id);
            _cache.Remove(id); // The bloom filter still thinks that ID is in the cache!!!
        }
    }
}
