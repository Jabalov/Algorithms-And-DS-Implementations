using Gma.DataStructures.StringSearch;

namespace M7Trie
{
    public class KeywordPrefixMatcher : KeywordMatcher
    {
        public KeywordPrefixMatcher() : base(new Trie<int>())
        {
        }
    }
}
