#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;
#define vi vector<int>

double get_optimal_value(int capacity, vi weights, vi values)
{
  double value = 0.0;
  int n = values.size();
  multimap<double, long, greater<double>> valuePerUnit_and_index;

  for (int i = 0; i < n; i++)
    valuePerUnit_and_index.insert(make_pair((double)values[i] / (double)weights[i], i));

  for (auto i = valuePerUnit_and_index.begin(); i != valuePerUnit_and_index.end(); i++)
  {
    if (capacity == 0)
      return value;

    double a = min(capacity, weights[i->second]);
    capacity -= a;
    value += a * (double)i->first;
  }

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
    cin >> values[i] >> weights[i];

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
