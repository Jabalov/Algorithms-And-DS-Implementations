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

vector<Node> tree;

void ino_traversal(int index, vector<int> &res)
{
  if (index == -1)
    return;

  ino_traversal(tree[index].left, res);
  res.push_back(tree[index].key);
  ino_traversal(tree[index].right, res);
}

void inO(vector<int> &res, const vector<Node> &tree)
{
  ino_traversal(0, res);
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
      if (res[i] < res[i - 1])
        return false;

    return true;
  }
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
