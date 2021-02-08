/*
 * IMPORTANT: Fetch the list of English words at https://github.com/dwyl/english-words
 * and extract to c:/tmp/words.txt
*/

using System;
using System.IO;

namespace M2HashCollisions
{
    public class WordProvider
    {
        string[] _words;

        public WordProvider()
        {
            var path = "c:/tmp/words.txt";
            try
            {
                _words = File.ReadAllLines(path);
            }
            catch(Exception e)
            {
                Console.WriteLine();
                Console.WriteLine("Error!");
                Console.WriteLine($"Word list not fount at {path}!");
                Console.WriteLine("Go to https://github.com/dwyl/english-words, download the word list, and put it in that location.");
                Console.ReadLine();
                throw;
            }
        }

        public string[] Words
        {
            get { return _words; }
        }
    }
}
