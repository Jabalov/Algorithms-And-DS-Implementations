using System;
using System.Collections.Generic;
using System.Linq;

namespace M3BloomFilter
{
    public interface ICache
    {
        void Add(int key, Media content);
        bool ContainsKey(int key);
        void Remove(int key);
        Media Get(int key);
        void PrintStats();
    }

    public class Cache : ICache
    {
        private Dictionary<int, int> key2readCount = new Dictionary<int, int>();
        private Dictionary<int, Media> key2content = new Dictionary<int, Media>();

        public void Add(int key, Media content)
        {
            key2content.Add(key, content);
            key2readCount.Add(key, 0);
        }

        public void Remove(int key)
        {
            key2content.Remove(key);
            key2readCount.Remove(key);
        }

        public bool ContainsKey(int key)
        {
            return key2content.ContainsKey(key);
        }

        public Media Get(int key)
        {
            key2readCount[key]++;
            return key2content[key];
        }

        public void PrintStats()
        {
            var total = key2content.Count;
            var oneOff = key2readCount.Where(x => x.Value == 0).ToList().Count;
            Console.WriteLine($"Cache entries: {total}");
            Console.WriteLine($"One-off entries: {oneOff} ({Math.Round(100.0 * oneOff / total, 0)}%)");
        }
    }
}
