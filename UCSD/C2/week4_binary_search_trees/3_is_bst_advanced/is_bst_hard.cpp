#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int index;
  int key;
  int left;
  int right;

  Node() : index(0), key(0), left(-1), right(-1) {}
  Node(int index_, int key_, int left_, int right_) : index(index_), key(key_), left(left_), right(right_) {}
};

vector<Node> tree;

void inO_traversal(int index, vector<int> &res)
{
  if (index == -1)
    return;

  inO_traversal(tree[index].left, res);
  res.push_back(tree[index].index);
  inO_traversal(tree[index].right, res);
}

void inO(std::vector<int> &res, const vector<Node> &tree)
{
  inO_traversal(0, res);
}

bool IsBinarySearchTree(const vector<Node> &tree)
{
  if (tree.size() == 0)
    return true;

  else
  {

    vector<int> res;
    inO(res, tree);

    for (int i = 1; i < res.size(); i++)
    {
      if (tree[res[i]].key < tree[res[i - 1]].key)
        return false;

      else if (tree[res[i]].key == tree[res[i - 1]].key && res[i - 1] == tree[res[i]].left)
        return false;
    }
    return true;
  }
}

int main()
{
  int nodes;
  cin >> nodes;

  for (int i = 0; i < nodes; ++i)
  {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(i, key, left, right));
  }

  if (IsBinarySearchTree(tree))
    cout << "CORRECT" << endl;

  else
    cout << "INCORRECT" << endl;

  return 0;
}