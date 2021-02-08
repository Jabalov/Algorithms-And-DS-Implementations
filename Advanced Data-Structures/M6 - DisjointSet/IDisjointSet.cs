using System.Collections.Generic;

namespace M6DisjointSet
{
    public interface IDisjointSet<T>
    {
        void MakeSet(T id);
        void Union(T id1, T id2);
        T FindSet(T id);

        List<T> GetSet(T id);
        List<List<T>> GetAllSets();
    }
}