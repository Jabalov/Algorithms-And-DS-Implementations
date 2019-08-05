#include <stdio.h>
#include <iostream>
using namespace std;

class Diagonal
{
private:
    int *A;
    int n;

public:
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }

    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    ~Diagonal()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getD() { return n; }
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int Diagonal::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void Diagonal::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                cout << A[i - 1] << " ";
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

    Diagonal D(d);

    int x;
    cout << "Enter All Elements\n";
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            if (i == j)
                cin >> x, D.Set(i, j, x);

    D.Display();
    return 0;
}