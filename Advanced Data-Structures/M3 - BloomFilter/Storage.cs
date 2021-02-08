using System.Threading;

namespace M3BloomFilter
{
    public interface IStorage
    {
        Media GetContent(int id);
        void RemoveContent(int id);
    }

    public class Storage : IStorage
    {
        int _msLatency = 0;

        public Storage(int msLatency = 0)
        {
            _msLatency = msLatency;
        }

        public Media GetContent(int id)
        {
            Thread.Sleep(_msLatency);
            return new Media(id);
        }

        public void RemoveContent(int id)
        {
            Thread.Sleep(_msLatency);
        }
    }
}
