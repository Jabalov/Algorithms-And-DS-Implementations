using System.Linq;
using Gma.DataStructures.StringSearch;
using System.Collections.Generic;
using M2HashCollisions;

namespace M7Trie
{
    public class KeywordMatcher : IKeywordMatcher
    {
        ITrie<int> _trie;
        WordProvider _wordProvider;

        public KeywordMatcher(ITrie<int> trieInstance)
        {
            _trie = trieInstance;
            _wordProvider = new WordProvider();
        }

        public void Init()
        {
            var index = 0;
            foreach (var word in _wordProvider.Words)
                _trie.Add(word.ToLower(), index++);
        }

        public IEnumerable<string> Match(string query, int maxMatches)
        {
            var results = _trie.Retrieve(query.ToLower()).Take(maxMatches);
            var words = results.Select(x => _wordProvider.Words[x].ToLower());
            return words;
        }

        public int Count()
        {
            return _wordProvider.Words.Count();
        }
    }

}
