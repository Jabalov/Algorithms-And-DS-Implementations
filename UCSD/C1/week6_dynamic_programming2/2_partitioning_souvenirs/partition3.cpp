#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

#define vi vector<int>
#define vii vector<vector<int>>
#define viii vector<vector<vector<int>>>
#define ll long long
using namespace std;

int partition3(vi &A)
{

  return 0;
}

int main()
{
  int n;
  cin >> n;
  vi A(n);
  for (size_t i = 0; i < A.size(); ++i)
    cin >> A[i];

  cout << partition3(A) << '\n';
}
