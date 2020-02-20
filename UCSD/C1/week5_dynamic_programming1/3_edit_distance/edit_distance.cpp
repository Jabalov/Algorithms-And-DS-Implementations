#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>

#define vi vector<int>
#define vii vector<vector<int>>
#define ll long long
using namespace std;

int edit_distance(const string &str1, const string &str2)
{
  int len_str1 = str1.length(), len_str2 = str2.length();
  vii dist((len_str1 + 1), vi(len_str2 + 1));

  for (int i = 0; i <= len_str1; i++)
    for (int j = 0; j <= len_str2; j++)
    {
      if (i == 0)
        dist[i][j] = j;

      else if (j == 0)
        dist[i][j] = i;

      else if (str1[i - 1] == str2[j - 1])
        dist[i][j] = dist[i - 1][j - 1];

      else
        dist[i][j] = 1 + min(min(dist[i][j - 1], dist[i - 1][j]), dist[i - 1][j - 1]);
    }

  return dist[len_str1][len_str2];
}

int main()
{
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
