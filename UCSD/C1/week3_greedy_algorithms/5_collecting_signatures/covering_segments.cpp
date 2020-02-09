#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
using std::vector;
#define vi vector<int>
#define ll long long

struct Segment
{
  int start, end;
};

bool sort_order(Segment i, Segment j)
{
  return i.end < j.end;
}

vi optimal_points(vector<Segment> &segments)
{
  vi points;
  sort(segments.begin(), segments.end(), sort_order);

  //write your code here
  ll point = segments[0].end;
  points.push_back(point);

  for (int i = 1; i < segments.size(); i++)
  {
    if (segments[i].start > point || segments[i].end < point)
      point = segments[i].end, points.push_back(point);
  }

  return points;
}

int main()
{
  int n;
  cin >> n;
  vector<Segment> segments(n);

  for (size_t i = 0; i < segments.size(); ++i)
    cin >> segments[i].start >> segments[i].end;

  vi points = optimal_points(segments);
  cout << points.size() << "\n";

  for (size_t i = 0; i < points.size(); ++i)
    cout << points[i] << " ";
}
