using System;

namespace M5RTree
{
    class Program
    {
        static void Main(string[] args)
        {
            var backend = new Backend(new UserStore());
            var alice = backend.AddUser(55.676098F, 12.568337F);
            Console.WriteLine($"Alice's position: long: {alice.Longitude}\tlat: {alice.Latitude}");

            Console.WriteLine($"Populating users...");
            Populate(backend, 100000);

            Console.WriteLine("Nearby users:");
            var nearbyUsers = backend.GetNearbyUsers(
                alice.Longitude,
                alice.Latitude,
                0.10F);
            foreach (var user in nearbyUsers)
                Console.WriteLine($"long: {user.Longitude}\tlat: {user.Latitude}\tID: {user.Id}");

            Console.WriteLine("Press enter to exit...");
            Console.ReadLine();
        }

        static void Populate(IBackend backend, int numUsers)
        {
            var rnd = new Random(123);
            for(int i=0; i<numUsers; i++)
            {
                backend.AddUser(Convert.ToSingle(50 + 10 * rnd.NextDouble()),
                    Convert.ToSingle(5 + 10 * rnd.NextDouble()));
            }
        }
    }
}
