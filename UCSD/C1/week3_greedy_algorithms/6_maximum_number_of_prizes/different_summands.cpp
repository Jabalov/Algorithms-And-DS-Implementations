#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
#define vi vector<int>
#define ll long long

vi optimal_summands(int n)
{
  vi summands;
  //write your code here
  ll s = 1;

  if (n <= 2)
    summands.push_back(n);

  else
  {
    do
    {
      n -= s;
      summands.push_back(s++);
    } while ((n - s) > summands[summands.size() - 1] + 1);
    summands.push_back(n);
  }

  return summands;
}

int main()
{
  int n;
  cin >> n;
  vi summands = optimal_summands(n);

  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
    cout << summands[i] << ' ';
}
