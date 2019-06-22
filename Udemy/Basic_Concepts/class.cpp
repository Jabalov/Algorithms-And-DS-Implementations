#include <bits\stdc++.h>
#include <stdlib.h>
using namespace std;

class rect
{
private:
    int len;
    int bred;

public:
    rect(int l, int b)
    {
        len = l, bred = b;
    }

    int area()
    {
        return len * bred;
    }

    void changeLen(int l)
    {
        len = l;
    }
};

int main()
{
    rect r(10, 2);
    cout << r.area();
}