using System;
using System.Diagnostics;

namespace M3BloomFilter
{
    class LoadGenerator
    {
        IContentProvider _contentProvider;
        Stopwatch _watch;

        public LoadGenerator(IContentProvider contentProvider)
        {
            _contentProvider = contentProvider;
        }

        public void Run(int numContentEntries, double oneOffFraction)
        {
            var numOneOffs = (int)(oneOffFraction * numContentEntries);
            var rnd = new Random();
            Media content;
            _watch = new Stopwatch();
            Console.Write("Executing test load... ");
            _watch.Start();

            // First, load the one-off entries:
            for (var i = 0; i < numOneOffs; i++)
                content = _contentProvider.GetContent(i);

            // Next, load the multi-off entries:
            for (var i = numOneOffs; i < numContentEntries; i++)
            {
                var numFetches = rnd.Next(2, 10);
                for (var c = 0; c < numFetches; c++)
                    content = _contentProvider.GetContent(i);
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
