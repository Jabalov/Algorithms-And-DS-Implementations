namespace M7Trie
{
    class Program
    {
        static void Main(string[] args)
        {
            var matcher = new KeywordPrefixMatcher();
            var simulator = new AutocompletionSimulator(matcher);
            simulator.Menu();
        }
    }
}