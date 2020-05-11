#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include <math.h>

#define HT_PRIME_1 10
#define HT_PRIME_2 20

static Item DELETED_ITEM = {NULL, NULL};

static Item *new_item(const char *k, const char *v)
{
    Item *item = (Item *)malloc(sizeof(Item));

    item->key = strdup(k);
    item->value = strdup(v);

    return item;
}

HashTable *new_hashTable()
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));

    hashTable->capacity = 53;
    hashTable->cnt = 0;
    hashTable->items = calloc((size_t)hashTable->capacity, sizeof(Item *));

    return hashTable;
}

static void delete_item(Item *item) { free(item->key), free(item->value), free(item); }

void delete_hashTable(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->capacity; i++)
    {
        Item *current = hashTable->items[i];
        if (current != NULL)
            delete_item(current);
    }

    free(hashTable->items), free(hashTable);
}

static int hashFunction(const char *s, const int a, const int m)
{
    long long hash = 0;
    const int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        hash += (long long)pow(a, length - (i + 1)) * s[i];
        hash %= m;
    }
    return (int)hash;
}

static int get_hashCode(const char *s, const int num, const int attempts)
{
    const int a = hashFunction(s, HT_PRIME_1, num);
    const int b = hashFunction(s, HT_PRIME_2, num);

    return (a + (attempts * (b + 1))) % num;
}

void insert(HashTable *hashTable, const char *key, const char *value)
{
    Item *item = new_item(key, value);
    int idx = get_hashCode(item->key, hashTable->capacity, 0);

    Item *current = hashTable->items[idx];

    int i = 1;
    while (current != NULL)
    {
        if (current != &DELETED_ITEM)
            if (strcmp(current->key, key) == 0)
            {
                delete_item(current);
                hashTable->items[idx] = item;
                return;
            }
        idx = get_hashCode(item->key, hashTable->capacity, i);
        current = hashTable->items[idx];
        i++;
    }

    hashTable->items[idx] = item;
    hashTable->cnt++;
}

char *search(HashTable *hashTable, const char *key)
{
    int idx = get_hashCode(key, hashTable->capacity, 0);
    Item *item = hashTable->items[idx];

    int i = 0;
    while (item != NULL)
    {
        if (item != &DELETED_ITEM)
            if (strcmp(item->key, key) == 0)
                return item->value;

        idx = get_hashCode(key, hashTable->capacity, i);
        item = hashTable->items[idx];
        i++;
    }

    return NULL;
}

void delete_pair(HashTable *hashTable, const char *key)
{
    int idx = get_hashCode(key, hashTable->capacity, 0);
    Item *item = hashTable->items[idx];
    int i = 1;
    while (item != NULL)
    {
        if (item != &DELETED_ITEM)
        {
            if (strcmp(item->key, key) == 0)
            {
                delete_item(item);
                hashTable->items[idx] = &DELETED_ITEM;
            }
        }

        idx = get_hashCode(key, hashTable->capacity, i);
        item = hashTable->items[idx];
        i++;
    }

    hashTable->cnt--;
}