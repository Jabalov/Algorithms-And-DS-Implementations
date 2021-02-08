using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using Extensions.Data;

namespace M2HashCollisions
{
    class Program
    {
        const int imageSize = 500;
        static string _imagePath = "c:/tmp";

        static void Main(string[] args)
        {
            var wordProvider = new WordProvider();
            Console.WriteLine("Executing tests...");

            var numbers = new List<int>();
            for (int i = 0; i < 1000000; i++)
                numbers.Add(i);
            RunAll(numbers, "numbers");

            var stringNumbers = numbers.Select(x => x.ToString()).ToList();
            RunAll(stringNumbers, "numStrings");

            var guids = new List<string>();
            for (int i = 0; i < 1000000; i++)
                guids.Add(Guid.NewGuid().ToString());
            RunAll(guids, "guids");

            RunAll(wordProvider.Words.ToList(), "words");

            Console.WriteLine($"\nImages written to {_imagePath}");
            Console.WriteLine("Done. Press a key.");
            Console.ReadLine();
        }

        static void RunAll<TKey>(List<TKey> keys, string content)
        {
            var xxHash = XXHash32.Create();
            xxHash.Initialize();
            var murmur = new System.Data.HashFunction.MurmurHash3();
            var city = new System.Data.HashFunction.CityHash();

            // Default:
            DrawHashes(keys, x => x.GetHashCode(), $"hash_{content}_default");

            // xxHash:
            DrawHashes(keys, x =>
            {
                var h = xxHash.ComputeHash(ToBytes((dynamic)x));
                return BitConverter.ToInt32(h, 0);
            },
            $"hash_{content}_xx");

            // Murmur:
            DrawHashes(keys, x =>
            {
                var h = murmur.ComputeHash(ToBytes((dynamic)x));
                return BitConverter.ToInt32(h, 0);
            },
            $"hash_{content}_murmur");

            // City:
            DrawHashes(keys, x =>
            {
                var h = city.ComputeHash(ToBytes((dynamic)x));
                return BitConverter.ToInt32(h, 0);
            },
            $"hash_{content}_city");
        }

        static byte[] ToBytes(int value)
        {
            return BitConverter.GetBytes(value);
        }
        static byte[] ToBytes(string value)
        {
            return Encoding.ASCII.GetBytes(value);
        }

        static void DrawHashes<TKey>(List<TKey> keys, Func<TKey, int> hashFunction, string filename)
        {
            Console.Write(filename + "... ");
            var hash2count = new Dictionary<int, int>();
            foreach(TKey key in keys)
            {
                var hash = hashFunction(key);
                if (!hash2count.ContainsKey(hash))
                    hash2count.Add(hash, 1);
                else
                    hash2count[hash]++;
            }
            var collisions = keys.Count - hash2count.Keys.Count;
            Console.WriteLine("collisions: " + collisions);
            DrawHash(hash2count, filename);
        }

        static void DrawHash(Dictionary<int, int> hash2count, string filename)
        {
            double scale = 1.0 * imageSize * imageSize / uint.MaxValue;
            var map = new Dictionary<int, int>();
            var max = 0;
            foreach (var pair in hash2count)
            {
                int newKey = (int)(((uint)pair.Key) * scale);
                //Console.WriteLine(pair.Key + "\t" + newKey);
                if (!map.ContainsKey(newKey))
                    map.Add(newKey, pair.Value);
                else
                    map[newKey] += pair.Value;
                if (map[newKey] > max)
                    max = map[newKey];
            }

            using (Bitmap image = new Bitmap(imageSize, imageSize))
            {
                var g = Graphics.FromImage(image);
                g.Clear(Color.FromArgb(0, 0, 0));
                g.Save();
                foreach (var pair in map)
                {
                    int y = pair.Key / imageSize;
                    int x = pair.Key % imageSize;
                    var value = Math.Min(255, 255 * pair.Value / max);
                    var color = Color.FromArgb(value, value, value);
                    image.SetPixel(x, y, color);
                }
                image.Save(_imagePath + "/" + filename + ".png", System.Drawing.Imaging.ImageFormat.Png);
            }
        }
    }
}