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

    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;

        for (int j = i - 1; j >= 0; j--)
            if (A[j] <= A[j + 1] && A[j] <= A[i])
                cnt++;
            else
                break;

        for (int k = i + 1; k < n; k++)
            if (A[k - 1] >= A[k] && A[k] <= A[i])
                cnt++;
            else
                break;

        maxi = max(maxi, cnt);
    }

    cout << maxi;

#ifdef LOCAL
    cout << "\n\n\nExecution time: " << (clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}