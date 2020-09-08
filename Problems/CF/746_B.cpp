#include <bits\stdc++.h>
using namespace std;

template <class T>
using V = vector<T>;

template <class T>
using VV = V<V<T>>;

template <class T>
using VVV = VV<V<T>>;

using ll = long long;
using pii = pair<int, int>;
using vi = V<int>;
using vii = V<pii>;
using vvi = VV<int>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using si = set<int>;
using usi = unordered_set<int>;

int N;
ll mem[1 << 19][20], sum[20];
vi a;

int main()
{
#ifdef LOCAL
    auto stTime = clock();
    //	freopen("in.txt", "r", stdin);
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
    ios::sync_with_stdio(false);
    cout.precision(10);
    cin.tie(0);

    int n;
    cin >> n;

    string decoded;
    cin >> decoded;

    list<char> encoded;

    int i = 0;
    if (n & 1)
        encoded.push_back(decoded[0]), i = 1;

    bool left = true;

    for (i; i < n; i++)
    {
        if (left)
            encoded.push_front(decoded[i]), left = false;

        else
            encoded.push_back(decoded[i]), left = true;
    }

    for_each(encoded.begin(), encoded.end(), [](const auto &e) {
        cout << e;
    });

#ifdef LOCAL
    cout << "\n\n\nExecution time: " << (clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}