#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder
{

private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i)
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  int left(int p)
  {
    int left = 2 * p + 1;
    if (left < data_.size())
      return left;
    else
      return -1;
  }

  int right(int p)
  {
    int right = 2 * p + 2;
    if (right < data_.size())
      return right;
    else
      return -1;
  }

  int parent(int child)
  {
    if (child == 0)
      return -1;

    int p = (child - 1) / 2;
    return p;
  }

  void down(int i)
  {
    int idx = i;
    int l = left(i), r = right(i);

    if (l <= data_.size() - 1 && data_[l] < data_[idx])
      idx = l;

    if (r <= data_.size() - 1 && data_[r] < data_[idx])
      idx = r;

    if (i != idx)
    {
      swap(data_[i], data_[idx]);
      swaps_.push_back(make_pair(i, idx));
      down(idx);
    }
  }

  void GenerateSwaps()
  {
    swaps_.clear();
    int n = data_.size();
    for (int i = (n - 1) / 2; i + 1 != 0; i--)
      down(i);
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap;
  heap.Solve();
  return 0;
}
