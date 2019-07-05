#include <stdio.h>

struct Diagonal
{
    int A[10];
    int n;
};

void Set(struct Diagonal *d, int i, int j, int x)
{
    if (i == j)
        d->A[i - 1] = x;
}

int Get(struct Diagonal d, int i, int j)
{
    if (i == j)
        return d.A[i - 1];
    else
        return 0;
}

void Display(struct Diagonal d)
{
    int i, j;
    for (i = 0; i < d.n; i++)
    {
        for (j = 0; j < d.n; j++)
        {
            if (i == j)
                printf("%d ", d.A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Diagonal d;
    d.n = 4;
    Set(&d, 1, 1, 5);
    Set(&d, 2, 2, 8);
    Set(&d, 3, 3, 9);
    Set(&d, 4, 4, 12);

    Display(d);
}