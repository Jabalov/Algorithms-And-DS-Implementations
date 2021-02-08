using M7Trie;

namespace M8SuffixTree
{
    class Program
    {
        static void Main(string[] args)
        {
            var matcher = new KeywordInfixMatcher(false);
            var simulator = new AutocompletionSimulator(matcher);
            simulator.Menu();
        }
    }
}
