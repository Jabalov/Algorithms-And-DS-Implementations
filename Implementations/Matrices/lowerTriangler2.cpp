#include <stdio.h>
#include <iostream>
using namespace std;

class LowerT
{
private:
    int *A;
    int n;

public:
    LowerT()
    {
        n = 2;
        A = new int[n * (n + 1) / 2];
    }

    LowerT(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }

    ~LowerT()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getD() { return n; }
};

void LowerT::Set(int i, int j, int x)
{
    if (i >= j)
        A[(i * (i - 1) / 2) + j - 1] = x;
}

int LowerT::Get(int i, int j)
{
    if (i >= j)
        return A[(i * (i - 1) / 2) + j - 1];
    else
        return 0;
}

void LowerT::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= j)
                cout << A[(i * (i - 1) / 2) + j - 1] << " ";
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

    LowerT T(d);

    int x;
    cout << "Enter All Elements\n";
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            if (i >= j)
                cin >> x, T.Set(i, j, x);

    T.Display();
    return 0;
}