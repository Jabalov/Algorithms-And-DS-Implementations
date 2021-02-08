using RTree;
using System.Collections.Generic;

namespace M5RTree
{
    class Backend : IBackend
    {
        RTree<int> _userMap;
        IUserStore _userStore;
 
        public Backend(IUserStore userStore)
        {
            _userMap = new RTree<int>();
            _userStore = userStore;
        }

        public User AddUser(float longitude, float latitude)
        {
            int userId = _userStore.AddUser(longitude, latitude);
            var boundingBox = GetBoundingBox(longitude, latitude, 0); 
            _userMap.Add(boundingBox, userId);
            return _userStore.GetUser(userId);
        }

        public List<User> GetNearbyUsers(float longitude, float latitude,
            float maxDistance)
        {
            var boundingBox = GetBoundingBox(longitude, latitude, maxDistance);
            List<int> containedIds = _userMap.Contains(boundingBox);
            return _userStore.GetUsers(containedIds);
        }

        Rectangle GetBoundingBox(float centerLon, float centerLat, float sideLength)
        {
            var lonMin = centerLon - sideLength / 2;
            var lonMax = centerLon + sideLength / 2;
            var latMin = centerLat - sideLength / 2;
            var latMax = centerLat + sideLength / 2;
            var boundingBox = new Rectangle(
                new float[] { lonMin, latMin, 0 },
                new float[] { lonMax, latMax, 0 });
            return boundingBox;
        }

    }
}
