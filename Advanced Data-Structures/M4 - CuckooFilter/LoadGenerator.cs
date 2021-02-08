using System;
using System.Diagnostics;
using M3BloomFilter;

namespace M4CuckooFilter
{
    class LoadGenerator
    {
        IContentProvider _contentProvider;
        Stopwatch _watch;

        public LoadGenerator(IContentProvider contentProvider)
        {
            _contentProvider = contentProvider;
        }

        public void Run(int numContentEntries, double oneOffFraction, double deletionFraction, int numLoops)
        {
            var numOneOffs = (int)(oneOffFraction * numContentEntries);
            var numDeletes = (int)(deletionFraction * numContentEntries);
            var rnd = new Random();
            Media content;
            _watch = new Stopwatch();
            Console.Write("Executing test load... ");
            _watch.Start();

            for (int l = 0; l < numLoops; l++)
            {
                Console.Write(l + " ");
                int idxStart = l * numContentEntries;

                // First, load the one-off entries:
                for (var i = 0; i < numOneOffs; i++)
                {
                    int id = idxStart + i;
                    content = _contentProvider.GetContent(id);
                }

                // Next, load the multi-off entries:
                for (var i = numOneOffs; i < numContentEntries; i++)
                {
                    int id = idxStart + i;
                    var numFetches = rnd.Next(2, 10);
                    for (var c = 0; c < numFetches; c++)
                        content = _contentProvider.GetContent(id);
                }

                // Delete some of the content:
                for (var i = 0; i < numDeletes; i++)
                {
                    int id = idxStart + i;
                    _contentProvider.RemoveContent(id);
                }
            }

            _watch.Stop();
            Console.WriteLine("done");
        }

        public TimeSpan GetElapsedTime()
        {
            return _watch.Elapsed;
        }
    }
}
