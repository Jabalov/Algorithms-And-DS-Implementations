#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    HashTable *ht = new_hashTable();
    delete_hashTable(ht);
    printf("\nDone..");
}