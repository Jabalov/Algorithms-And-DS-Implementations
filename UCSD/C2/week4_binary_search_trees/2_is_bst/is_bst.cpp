#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void inO(const vector<Node> &tree, int idx, vector<int> &result)
{
  if (tree[idx].left != -1)
    inO(tree, tree[idx].left, result);

  result.push_back(tree[idx].key);

  if (tree[idx].right != -1)
    inO(tree, tree[idx].right, result);
}

bool IsBinarySearchTree(const vector<Node> &tree)
{
  vector<int> in_order, not_sorted_vector;
  inO(tree, 0, in_order);

  not_sorted_vector = in_order;
  sort(in_order.begin(), in_order.end());

  for (int i = 0; i < tree.size(); i++)
    if (not_sorted_vector[i] != in_order[i])
      return false;

  return true;
}

int main()
{
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i)
  {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }

  if (IsBinarySearchTree(tree))
    cout << "CORRECT" << endl;

  else
    cout << "INCORRECT" << endl;

  return 0;
}
