using System;
using System.Collections.Generic;
using System.Linq;

namespace M6DisjointSet
{
    public class DisjointSetHash<T> : IDisjointSet<T> where T:IEquatable<T> 
    {
        Dictionary<T, T> _itemId2SetId = new Dictionary<T, T>();
        Dictionary<T, List<T>> _setId2ItemIds = new Dictionary<T, List<T>>();

        public void MakeSet(T id)
        {
            if (_itemId2SetId.ContainsKey(id))
                throw new ArgumentException("id already added as set");

            // Initially, the item gets a dedicated set, with the set ID = id: 
            _itemId2SetId.Add(id, id);
            _setId2ItemIds.Add(id, new List<T>() { id }); // The set only contains that item
        }

        public void Union(T id1, T id2)
        {
            if (!_itemId2SetId.ContainsKey(id1))
                throw new ArgumentException("id1 not created as set yet");
            if (!_itemId2SetId.ContainsKey(id2))
                throw new ArgumentException("id2 not created as set yet");

            var setId1 = _itemId2SetId[id1];
            var setId2 = _itemId2SetId[id2];

            // Do nothing if the items already belong to the same set:
            if (setId1.Equals(setId2))
                return;

            if (_setId2ItemIds[setId1].Count > _setId2ItemIds[setId2].Count)
                Merge(setId1, setId2);
            else
                Merge(setId2, setId1);
        }

        private void Merge(T setId1, T setId2)
        {
            // All items in set 2 will be moved to set 1:
            var itemsToBeMoved = _setId2ItemIds[setId2];
            foreach (T itemId in itemsToBeMoved)
                _itemId2SetId[itemId] = setId1;

            // Add the items from set 2 to set 1:
            _setId2ItemIds[setId1].AddRange(itemsToBeMoved);
            // Set 2 no longer exists. Remove it:
            _setId2ItemIds.Remove(setId2);
        }

        public List<T> GetSet(T id)
        {
            var setId = _itemId2SetId[id];
            return _itemId2SetId.Where(kv => kv.Value.Equals(setId)).Select(kv => kv.Key).ToList();
        }

        public List<List<T>> GetAllSets()
        {
            var setId2ItemIds = new Dictionary<T, List<T>>();
            foreach (var kv in _itemId2SetId)
            {
                if (!setId2ItemIds.ContainsKey(kv.Value))
                    setId2ItemIds.Add(kv.Value, new List<T>());
                setId2ItemIds[kv.Value].Add(kv.Key);
            }

            return setId2ItemIds.Values.ToList();
        }

        public T FindSet(T id)
        {
            if (!_itemId2SetId.ContainsKey(id))
                throw new ArgumentException("id not created as set yet");
            return _itemId2SetId[id];
        }
    }

}