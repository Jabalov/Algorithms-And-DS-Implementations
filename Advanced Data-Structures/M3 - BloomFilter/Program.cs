using System;

namespace M3BloomFilter
{
    class Program
    {
        static void Main(string[] args)
        {
            var cache = new Cache();
            var storage = new Storage();

            // IContentProvider contentProvider = new ContentProvider(cache, storage);
            IContentProvider contentProvider = new ContentProviderBloom(cache, storage);

            var numContentEntries = 1000000;
            var oneOffFraction = 0.65;

            var loadGenerator = new LoadGenerator(contentProvider);
            loadGenerator.Run(numContentEntries, oneOffFraction);

            cache.PrintStats();

            Console.WriteLine("Press enter to exit");
            Console.ReadLine();
        }
    }
}
