#include <stdio.h>
#include <iostream>
using namespace std;

class triD
{
private:
    int *A;
    int n;

public:
    triD()
    {
        n = 2;
        A = new int[3 * n - 2];
    }

    triD(int n)
    {
        this->n = n;
        A = new int[3 * n - 2];
    }

    ~triD()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getD() { return n; }
};

void triD::Set(int i, int j, int x)
{
    if (i - j == 1)
        A[i - 1] = x;
    else if (i - j == 0)
        A[(n - 1) + (i - 1)] = x;
    else if (i - j == -1)
        A[(2 * n - 1) + (i - 1)] = x;
}

int triD::Get(int i, int j)
{
    if (i - j == 1)
        return A[i - 1];
    else if (i - j == 0)
        return A[(n - 1) + (i - 1)];
    else if (i - j == -1)
        return A[(2 * n - 1) + (i - 1)];
    else
        return 0;
}

void triD::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - j == 1)
                cout << A[i - 1] << " ";
            else if (i - j == 0)
                cout << A[(n - 1) + (i - 1)] << " ";
            else if (i - j == -1)
                cout << A[(2 * n - 1) + (i - 1)] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions\n";
    cin >> d;

    triD T(d);

    int x;
    cout << "Enter All Elements\n";
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            if (abs(i - j) <= 1)
                cin >> x, T.Set(i, j, x);

    T.Display();
    return 0;
}