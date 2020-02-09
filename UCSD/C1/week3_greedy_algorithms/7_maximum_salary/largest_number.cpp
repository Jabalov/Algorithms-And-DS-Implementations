#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
#define vi vector<int>
#define ll long long

bool comparison(string a, string b)
{
  stringstream ret;
  int tmp1, tmp2;

  ret << a, ret << b, ret >> tmp1;

  ret.clear();

  ret << b, ret << a, ret >> tmp2;

  return tmp1 > tmp2;
}

string largest_number(vector<string> a)
{
  //write your code here
  stringstream ret;
  sort(a.begin(), a.end(), comparison);
  for (size_t i = 0; i < a.size(); i++)
    ret << a[i];

  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<string> a(n);

  for (size_t i = 0; i < a.size(); i++)
    cin >> a[i];

  cout << largest_number(a);
}
