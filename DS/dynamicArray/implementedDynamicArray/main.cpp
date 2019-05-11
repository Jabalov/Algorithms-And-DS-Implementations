#include <array.h>
#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    Array<int> A;

    for (int i = 0; i < 10; i++)
        A.push(i);

    A.print();
    cout << "Popping " << A.pop() << "\n";
    A.push(123123);
    A.set(2, 99999);
    A.print();

    return 0;
}
