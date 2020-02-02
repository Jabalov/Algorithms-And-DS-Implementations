#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define vi vector<int>

double get_optimal_value(int capacity, vi weights, vi values)
{
  double value = 0.0;

  // write your code here

  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vi values(n);
  vi weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
