#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
#define ll long long

struct Node
{
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool is_bst(const vector<Node> &tree, int index, ll min, ll max)
{

  if (tree[index].key < min || tree[index].key >= max)
    return false;

  else
  {
    if (tree[index].left == -1 && tree[index].right == -1)
      return true;

    else if (tree[index].right == -1)
      return is_bst(tree, tree[index].left, min, tree[index].key);

    else if (tree[index].left == -1)
      return is_bst(tree, tree[index].right, tree[index].key, max);

    else
      return is_bst(tree, tree[index].left, min, tree[index].key) && is_bst(tree, tree[index].right, tree[index].key, max);
  }
}

bool IsBinarySearchTree(const vector<Node> &tree)
{
  ll inf = LLONG_MAX;
  return is_bst(tree, 0, -1, inf);
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
