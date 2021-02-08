using Gma.DataStructures.StringSearch;
using M7Trie;

namespace M8SuffixTree
{
    public class KeywordInfixMatcher : KeywordMatcher
    {
        public KeywordInfixMatcher(bool useUkkonen)
            : base(useUkkonen ?
                  (ITrie<int>)new UkkonenTrie<int>() :
                  new SuffixTrie<int>(1))
        {
        }
    }
}
