using System;
using System.Collections.Generic;
using System.Linq;

namespace M6DisjointSet
{
    public class DisjointSetForest<T> : IDisjointSet<T> where T:IEquatable<T> 
    {
        Dictionary<T, Node<T>> _itemId2Node = new Dictionary<T, Node<T>>();

        public void MakeSet(T id)
        {
            if (_itemId2Node.ContainsKey(id))
                throw new ArgumentException("id already added as set");

            var set = new Node<T>(id);
            _itemId2Node.Add(id, set);
        }

        public T FindSet(T id)
        {
            if (!_itemId2Node.ContainsKey(id))
                throw new ArgumentException("id not created as set yet");

            var node = _itemId2Node[id];
            return FindSet(node).Value;
        }

        private Node<T> FindSet(Node<T> node)
        {
            var parent = node.Parent;
            if (parent == node)
                return parent;

            node.Parent = FindSet(node.Parent); // Path compression

            return node.Parent; // The root node will return itself here
        }

        public void Union(T id1, T id2)
        {
            if (!_itemId2Node.ContainsKey(id1))
                throw new ArgumentException("id1 not created as set yet");
            if (!_itemId2Node.ContainsKey(id2))
                throw new ArgumentException("id2 not created as set yet");

            var setNode1 = FindSet(_itemId2Node[id1]);
            var setNode2 = FindSet(_itemId2Node[id2]);

            if (setNode1.Value.Equals(setNode2.Value))
                return;

            if (setNode1.Rank > setNode2.Rank)
            {
                setNode2.Parent = setNode1;
                return;
            }

            setNode1.Parent = setNode2;
            if (setNode1.Rank.Equals(setNode2.Rank))
                setNode2.Rank++;
        }

        public List<T> GetSet(T id)
        {
            var setId = FindSet(id);
            var set = new List<T>();
            return _itemId2Node.Values.Where(node => FindSet(node.Value).Equals(setId)).Select(node => node.Value).ToList();
        }

        public List<List<T>> GetAllSets()
        {
            var setId2Collection = new Dictionary<T, List<T>>();
            foreach(var pair in _itemId2Node)
            {
                var id = pair.Key;
                var setId = FindSet(id);
                if (!setId2Collection.ContainsKey(setId))
                    setId2Collection.Add(setId, new List<T>() { id });
                else
                    setId2Collection[setId].Add(id);
            }
            return setId2Collection.Values.ToList();
        }
    }

    class Node<T>
    {
        public T Value { get; }
        public Node<T> Parent { get; set; }
        public int Rank { get; set; }

        public Node(T data)
        {
            Value = data;
            Parent = this;
            Rank = 0;
        }
    }
}
