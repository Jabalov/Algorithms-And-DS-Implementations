using System.Collections.Generic;

namespace M6DisjointSet
{
    public class InteractionMonitor : IInteractionMonitor
    {
        private IDisjointSet<int> _ds;

        public InteractionMonitor(IDisjointSet<int> disjointSet)
        {
            _ds = disjointSet;
        }
 
        public void RegisterUser(int userId)
        {
            _ds.MakeSet(userId);
        }

        public void RegisterInteraction(int userId1, int userId2)
        {
            _ds.Union(userId1, userId2);
        }

        public List<int> GetInteractionGroup(int userId)
        {
            return _ds.GetSet(userId);
        }

        public List<List<int>> GetAllInteractionGroups()
        {
            return _ds.GetAllSets();
        }
    }
}
