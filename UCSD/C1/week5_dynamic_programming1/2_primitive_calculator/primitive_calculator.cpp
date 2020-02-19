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

vi optimal_sequence_dp(int input_number)
{
  vi seq;
  vi num_ops(input_number + 1, 10e3);
  num_ops[0] = 0;

  for (int m = 1; m <= input_number; m++)
  {
    int current = num_ops[m - 1] + 1;

    if (m % 2 == 0)
      current = min(current, num_ops[m / 2] + 1);

    if (m % 3 == 0)
      current = min(current, num_ops[m / 3] + 1);

    if (current < num_ops[m])
      num_ops[m] = current;
  }

  int n = input_number;

  while (n > 0)
  {
    seq.push_back(n);
    if (num_ops[n - 1] == num_ops[n] - 1)
      n -= 1;

    else if ((n % 2 == 0) && (num_ops[n / 2] == num_ops[n] - 1))
      n /= 2;

    else if ((n % 3 == 0) && (num_ops[n / 3] == num_ops[n] - 1))
      n /= 3;
  }

  reverse(seq.begin(), seq.end());
  return seq;
}

int main()
{
  int n;
  cin >> n;
  vi seq = optimal_sequence_dp(n);

  cout << seq.size() - 1 << endl;

  for (size_t i = 0; i < seq.size(); ++i)
    cout << seq[i] << " ";
}
