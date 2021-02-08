using System.Collections.Generic;

namespace M5RTree
{
    interface IBackend
    {
        User AddUser(float longitude, float latitude);
        List<User> GetNearbyUsers(float longitude, float latitude, float maxDistance);
    }
}
