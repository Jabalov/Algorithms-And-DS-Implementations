#include <stdio.h>
#include "chains.h"

int hash_func(int i)
{
    return i % 10;
}

void insert(struct Node **p, int x)
{
    int idx = hash_func(x);
    sorted_insert(&p[idx], x);
}

int main()
{
    struct Node *hash_table[10], *tmp;

    for (int i = 0; i < 10; i++)
        hash_table[i] = NULL;

    insert(hash_table, 12);
    insert(hash_table, 22);
    insert(hash_table, 42);

    tmp = search(hash_table[hash_func(22)], 22);

    printf("%d ", tmp->data);
}