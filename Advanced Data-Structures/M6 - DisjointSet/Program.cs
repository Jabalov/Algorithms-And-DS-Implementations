using System;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace M6DisjointSet
{
    class Program
    {
        static void Main(string[] args)
        {
            var numUsers = 10000000;
            var numInteractions = 25000000;

            Console.WriteLine("Forest:");
            SimulateLoad(numUsers, numInteractions,
                new InteractionMonitor(new DisjointSetForest<int>()));

            Console.WriteLine("\nHash:");
            SimulateLoad(numUsers, numInteractions,
                new InteractionMonitor(new DisjointSetHash<int>()));

            Console.WriteLine("\nDone. Press enter to exit.");
            Console.ReadKey();

        }

        static void SimulateLoad(int numUsers, int numInteractions,
            IInteractionMonitor monitor)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US", false); 

            var watch = new Stopwatch();
            var rnd = new Random(123); // Constant seed for repeatable experiments
            Console.Write($"Creating {numUsers:n0} users...\t\t");

            watch.Start();
            for (var i = 0; i < numUsers; i++)
                monitor.RegisterUser(i);
            Console.WriteLine($"done in {watch.Elapsed.TotalSeconds:0.000}");

            Console.Write($"Performing {numInteractions:n0} interactions...\t");
            watch.Restart();
            for (var i = 0; i < numInteractions; i++)
            {
                var user1 = rnd.Next(numUsers);
                var user2 = rnd.Next(numUsers);
                monitor.RegisterInteraction(user1, user2);
            }
            Console.WriteLine($"done in {watch.Elapsed.TotalSeconds:0.000}");

            Console.Write($"Getting all interaction groups...\t");
            watch.Restart();
            var allGroups = monitor.GetAllInteractionGroups();
            Console.WriteLine($"done in {watch.Elapsed.TotalSeconds:0.000}");
            Console.WriteLine("Number of groups: {0:n0}", allGroups.Count());
        }
    }
}
