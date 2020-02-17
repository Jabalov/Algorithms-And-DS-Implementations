#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#define vi vector<int>
#define ll long long
using namespace std;

vi optimal_sequence(int n)
{
  vi sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
      n /= 3;

    else if (n % 2 == 0)
      n /= 2;

    else
      n--;
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vi optimal_sequence_dp(int n)
{
}

int main()
{
  int n;
  cin >> n;
  vi sequence = optimal_sequence(n);
  cout << sequence.size() - 1 << endl;

  for (size_t i = 0; i < sequence.size(); ++i)
    cout << sequence[i] << " ";
}
