using RTree;
using System.Collections.Generic;
using System.Linq;
using System;

namespace M5RTree
{
    class User
    {
        public int Id { get; set; }
        public float Longitude { get; set; }
        public float Latitude { get; set; }
    }

    interface IUserStore
    {
        List<User> GetUsers(List<int> ids);
        User GetUser(int id);
        int AddUser(float longitude, float latitude);
    }

    class UserStore : IUserStore
    {
        int _nextId = 1;
        Dictionary<int, User> _userId2User;

        public UserStore()
        {
            _userId2User = new Dictionary<int, User>();
        }

        public User GetUser(int id)
        {
            return _userId2User[id];
        }

        public List<User> GetUsers(List<int> ids)
        {
            return ids.Select(id => _userId2User[id]).ToList();
        }

        public int AddUser(float longitude, float latitude)
        {
            var user = new User { Id = _nextId, Longitude = longitude, Latitude = latitude };
            _userId2User.Add(_nextId, user);
            _nextId++;
            return user.Id;
        }
    }
}
