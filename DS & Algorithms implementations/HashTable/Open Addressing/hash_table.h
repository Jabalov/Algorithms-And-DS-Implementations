#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *key, *value;

} Item;

typedef struct
{
    int sz, cnt;
    Item **items;

} HashTable;

static Item *new_item(const char *k, const char *v);
HashTable *new_hashTable();
static void delete_item(Item *item);
void delete_hashTable(HashTable *hashTable);
static int hashFunction(const char *s, const int a, const int m);
//Open Addressing Double Hashing
static int get_hashCode(const char *s, const int num, const int attempts);

void insert(HashTable *hashTable, const char *key, const char *value);
char *search(HashTable *hashTable, const char *key);
void delete_pair(HashTable *hashTable, const char *key);