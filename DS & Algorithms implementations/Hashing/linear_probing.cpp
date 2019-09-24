#include <stdio.h>
#define SIZE 10

int hash_func(int key)
{
    return key % SIZE;
}
