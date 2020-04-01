#include <stdio.h>
#define SIZE 10

int hash_func(int key)
{
    return key % SIZE;
}

int probing(int A[], int x)
{
    int idx = hash_func(x);
    int i = 0;

    while (A[(idx + i) % SIZE] != 0)
        i++;

    return (idx + i) % SIZE;
}

void insert(int A[], int x)
{
    int idx = hash_func(x);
    int i = 0;

    while (A[idx] = !0)
        idx = probing(A, x);

    A[idx] = x;
}

int search(int A[], int x)
{
    int idx = hash_func(x);
    int i = 0;

    while (A[(idx + i) % SIZE] != x)
        i++;

    return (idx + i) % SIZE;
}

int main()
{
    int hash_table[10] = {0};

    insert(hash_table, 12);
    insert(hash_table, 25);
    insert(hash_table, 35);
    insert(hash_table, 26);
    printf("\nKey found at: %d\n", search(hash_table, 35));
    return 0;
}