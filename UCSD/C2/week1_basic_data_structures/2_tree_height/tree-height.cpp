#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif
using namespace std;
class Node;

class Node
{
public:
  int key;
  Node *parent;
  vector<Node *> children;

  Node()
  {
    this->parent = NULL;
  }

  void setParent(Node *theParent)
  {
    parent = theParent;
    parent->children.push_back(this);
  }
};

int main_with_large_stack_space()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<Node> nodes;
  int root = 0;
  nodes.resize(n);

  for (int child_index = 0; child_index < n; child_index++)
  {
    int parent_index;
    cin >> parent_index;

    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);

    nodes[child_index].key = child_index;

    if (parent_index == -1)
      root = child_index;
  }

  Node *parent = &nodes[root];
  queue<Node *> q;
  int height = 0;
  q.push(parent);

  while (!q.empty())
  {
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
      Node *front = q.front();
      for (auto child : front->children)
        q.push(child);

      q.pop();
    }
    height++;
  }

  cout << height << endl;
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
        cerr << "setrlimit returned result = " << result << endl;
      }
    }
  }

#endif
  return main_with_large_stack_space();
}
