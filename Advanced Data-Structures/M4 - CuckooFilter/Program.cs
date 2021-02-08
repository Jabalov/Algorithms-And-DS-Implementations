using M3BloomFilter;
using System;

namespace M4CuckooFilter
{
    class Program
    {
        static void Main(string[] args)
        {
            var cache = new Cache();
            var storage = new Storage();

            // IContentProvider contentProvider = new ContentProvider(cache, storage);
            IContentProvider contentProvider = new ContentProviderCuckoo(cache, storage);

            var numContentEntries = 1000000;
            var oneOffFraction = 0.65;
            var deletionFraction = 0.3;
            var numLoops = 5;

            var loadGenerator = new LoadGenerator(contentProvider);
            loadGenerator.Run(numContentEntries, oneOffFraction,
                deletionFraction, numLoops);

            cache.PrintStats();

            Console.WriteLine("Press enter to exit");
            Console.ReadLine();

        }
    }
}
