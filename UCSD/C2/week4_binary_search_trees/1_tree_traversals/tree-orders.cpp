#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

class TreeOrders
{
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;
  vector<int> result;

public:
  void read()
  {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++)
      cin >> key[i] >> left[i] >> right[i];
  }

  vector<int> in_order()
  {
    result.clear();
    inO(0);
    return result;
  }

  void inO(int index)
  {
    if (left[index] != -1)
      inO(left[index]);

    result.push_back(key[index]);

    if (right[index] != -1)
      inO(right[index]);
  }

  vector<int> pre_order()
  {
    result.clear();
    preO(0);
    return result;
  }

  void preO(int index)
  {
    result.push_back(key[index]);

    if (left[index] != -1)
      preO(left[index]);

    if (right[index] != -1)
      preO(right[index]);
  }

  vector<int> post_order()
  {
    result.clear();
    postO(0);
    return result;
  }

  void postO(int index)
  {
    if (left[index] != -1)
      postO(left[index]);

    if (right[index] != -1)
      postO(right[index]);

    result.push_back(key[index]);
  }
};

void print(vector<int> a)
{
  for (size_t i = 0; i < a.size(); i++)
  {
    if (i > 0)
      cout << ' ';

    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space()
{
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }
#endif

  return main_with_large_stack_space();
}
