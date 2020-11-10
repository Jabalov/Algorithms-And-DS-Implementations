#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<int> removeDuplicates(vector<int> A, int size)
{
    vector<int> Ans;
    unordered_map<int, bool> HelperMap;

    for (int i = 0; i < size; i++)
    {
        if (HelperMap.count(A[i]) == 0)
        {
            Ans.push_back(A[i]);
            HelperMap[A[i]] = true;
        }
    }

    return Ans;
}

int main()
{
    vector<int> a = {1, 5, 2, 4, 4, 3, 3, 6, 7, 1, 1, 2};
    vector<int> v = removeDuplicates(a, a.size());

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " " << endl;

    return 0;
}