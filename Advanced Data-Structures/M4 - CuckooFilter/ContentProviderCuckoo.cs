using M3BloomFilter;

namespace M4CuckooFilter
{
    public class ContentProviderCuckoo : IContentProvider
    {
        IStorage _storage;
        ICache _cache;
        CuckooFilter _cuckoo;
 
        public ContentProviderCuckoo(ICache cache, IStorage storage)
        {
            _cache = cache;
            _storage = storage;
            _cuckoo = new CuckooFilter(1500000, 0.01);
        }

        public Media GetContent(int id)
        {
            if (_cache.ContainsKey(id))
                return _cache.Get(id);

            var content = _storage.GetContent(id);

            var probablyFetchedBefore = _cuckoo.Contains(id);
            if (probablyFetchedBefore)
                _cache.Add(id, content);

            _cuckoo.Insert(id);
            return content;
        }

        public void RemoveContent(int id)
        {
            _storage.RemoveContent(id);
            _cache.Remove(id);
            _cuckoo.Remove(id);
        }
    }
}
