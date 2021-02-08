using System;
using System.Diagnostics;
using System.Globalization;
using System.Linq;
using System.Threading;

namespace M7Trie
{
    public class AutocompletionSimulator
    {
        IKeywordMatcher _matcher;

        public AutocompletionSimulator(IKeywordMatcher matcher)
        {
            _matcher = matcher;
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US", false);

            Init();
        }

        public void Menu()
        {
            Console.WriteLine();
            while (true)
            {
                Console.WriteLine("Make your choice...");
                Console.WriteLine("  1: Interactive");
                Console.WriteLine("  2: Simulation");
                Console.WriteLine("  esc: Exit");
                var key = Console.ReadKey();
                if (key.KeyChar == '1')
                    Interactive();
                else if (key.KeyChar == '2')
                    Simulate(1000000, 5, 10);
                else if (key.Key == ConsoleKey.Escape)
                    return;

                Console.Clear();
            }
        }

        private void Init()
        {
            Console.Write("Preparing index... ");
            var watch = new Stopwatch();
            watch.Start();
            _matcher.Init();
            Console.WriteLine($"done ({_matcher.Count():n0} words in {watch.Elapsed.TotalSeconds:0.000} s)");
        }

        public void Simulate(int numWords, int maxQueryLength, int maxMatches)
        {
            var alphabet = "abcdefghijklmnopqrstuvwxyz";
            var rnd = new Random(123); // Static seed for repeatability
            var watch = new Stopwatch();
            Console.Clear();
            Console.Write($"Performing {numWords * maxQueryLength:n0} autocompletions... ");
            watch.Start();
            for (var i = 0; i < numWords; i++)
            {
                var queryString = "";
                for (var l=0; l<5; l++)
                {
                    queryString += alphabet[rnd.Next(alphabet.Length)];
                    _matcher.Match(queryString, maxMatches);
                }
            }
            Console.WriteLine($"done in {watch.Elapsed.TotalSeconds:0.000} s");
            Console.WriteLine("Press enter...");
            Console.ReadLine();
        }

        public void Interactive()
        {
            var queryString = "";
            while (true)
            {
                Console.CursorVisible = false;
                Console.Clear();
                var prompt = "Query> ";
                Console.WriteLine(prompt + queryString + "_");
                var indent = new string(' ', prompt.Length);
                if (queryString.Length > 0)
                {
                    var matches = _matcher.Match(queryString, 10);
                    if (!matches.Any())
                        Console.WriteLine(indent + "<No matches>");
                    else
                    {
                        foreach (var match in matches)
                            Console.WriteLine(indent + match);
                    }
                }
                Console.WriteLine("\nPress esc to exit.");
                var key = Console.ReadKey();
                if (key.Key == ConsoleKey.Backspace)
                    queryString = queryString.Substring(0, queryString.Length - 1);
                else if (key.Key == ConsoleKey.Escape)
                    return;
                else
                    queryString += key.KeyChar;
            }
        }
    }
}
