#include <iostream>
using namespace std;

void f(int n, int sum)
{
    if (n == 0)
        return;

    int k = n % 10, j = n / 10;
    sum += k;
    f(j, sum);
    printf("%d ", k);
}

int main()
{
    f(2048, 0);
}