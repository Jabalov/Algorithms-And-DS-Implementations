using System.Collections.Generic;

namespace M7Trie
{
    public interface IKeywordMatcher
    {
        void Init();
        IEnumerable<string> Match(string query, int maxMatches);
        int Count();
    }
}
