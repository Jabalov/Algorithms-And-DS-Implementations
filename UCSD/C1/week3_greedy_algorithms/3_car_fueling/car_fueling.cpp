#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;
#define vi vector<int>
#define ll long long

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    ll cnt(0);
    if (tank > dist)
        return cnt;

    if ((dist - stops[stops.size() - 1]) > tank)
        return -1;

    ll last_start = 0;
    for (int i = 0; i < stops.size(); i++)
    {
        if (i && stops[i] - stops[i - 1] > tank)
            return -1;

        if (stops[i] - last_start > tank)
            cnt++, last_start = stops[i - 1];
    }

    if (dist - last_start > tank)
        cnt++;

    return cnt;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
