namespace M3BloomFilter
{
    public interface IContentProvider
    {
        Media GetContent(int id);
        void RemoveContent(int id);
    }

    public class ContentProvider : IContentProvider
    {
        IStorage _storage;
        ICache _cache;

        public ContentProvider(ICache cache, IStorage storage)
        {
            _cache = cache;
            _storage = storage;
        }

        public Media GetContent(int id)
        {
            if (_cache.ContainsKey(id))
                return _cache.Get(id);

            var content = _storage.GetContent(id);
            _cache.Add(id, content);

            return content;
        }

        public void RemoveContent(int id)
        {
 
        }
    }
}
