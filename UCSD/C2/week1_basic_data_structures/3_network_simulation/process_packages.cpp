#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Request
{
    Request(int arrival_time, int process_time) : arrival_time(arrival_time),
                                                  process_time(process_time)
    {
    }

    int arrival_time;
    int process_time;
};

struct Response
{
    Response(bool dropped, int start_time) : dropped(dropped),
                                             start_time(start_time)
    {
    }

    bool dropped;
    int start_time;
};

class Buffer
{
public:
    Buffer(int size) : size_(size),
                       finish_time_()
    {
    }

    Response Process(const Request &request)
    {
        // write your code here
    }

private:
    int size_;
    queue<int> finish_time_;
};

vector<Request> ReadRequests()
{
    vector<Request> requests;
    int count;
    cin >> count;
    for (int i = 0; i < count; ++i)
    {
        int arrival_time, process_time;
        cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

vector<Response> ProcessRequests(const vector<Request> &requests, Buffer *buffer)
{
    vector<Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const vector<Response> &responses)
{
    for (int i = 0; i < responses.size(); ++i)
        cout << (responses[i].dropped ? -1 : responses[i].start_time) << endl;
}

int main()
{
    int size;
    cin >> size;
    vector<Request> requests = ReadRequests();

    Buffer buffer(size);
    vector<Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
