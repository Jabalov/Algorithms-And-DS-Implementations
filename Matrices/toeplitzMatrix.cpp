#include <stdio.h>
#include <iostream>
using namespace std;

class toeplitzMatrix
{
private:
    int *A;
    int n;

public:
    toeplitzMatrix()
    {
        n = 2;
        A = new int[2 * n - 1];
    }

    toeplitzMatrix(int n)
    {
        this->n = n;
        A = new int[2 * n - 1];
    }

    ~toeplitzMatrix()
    {
        delete[] A;
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int getD() { return n; }
};

void toeplitzMatrix::Set(int i, int j, int x)
{
    if (i <= j)
        A[j - i] = x;
    else if (i > j)
        A[n + (i - j - 1)] = x;
}

int toeplitzMatrix::Get(int i, int j)
{
    if (j >= i)
        return A[j - i];
    else if (i > j)
        return A[n + (i - j - 1)];
    else
        return 0;
}

void toeplitzMatrix::Display()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j >= i)
                cout << A[j - i] << " ";
            else if (i > j)
                cout << A[n + (i - j - 1)] << " ";
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

    toeplitzMatrix T(d);

    int x;
    cout << "Enter All Elements\n";
    for (int i = 1; i <= d; i++)
        for (int j = 1; j <= d; j++)
            if (i == 1 || (j == 1 && i != 1))
                cin >> x, T.Set(i, j, x);

    cout << "\n\n";

    T.Display();
    return 0;
}