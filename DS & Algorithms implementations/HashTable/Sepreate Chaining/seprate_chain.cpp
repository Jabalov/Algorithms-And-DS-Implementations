#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

class HashTable
{
private:
    int num_of_Buckets;
    list<int> *table;

public:
    HashTable(int buckets);
    void insert_item(int x);
    void delete_item(int key);
    int hashFunction(int x) { return (x % num_of_Buckets); }
    void display();
};

HashTable::HashTable(int buckets)
{
    this->num_of_Buckets = buckets;
    table = new list<int>[num_of_Buckets];
}

void HashTable::insert_item(int key)
{
    int idx = hashFunction(key);
    table[idx].push_back(key);
}

void HashTable::delete_item(int key)
{
    int idx = hashFunction(key);

    list<int>::iterator i;
    for (i = table[idx].begin(); i != table[idx].end(); i++)
        if (*i == key)
            break;

    if (i != table[idx].end())
        table[idx].erase(i);
}

void HashTable::display()
{
    for (int i = 0; i < num_of_Buckets; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
    int elements[] = {15, 11, 27, 8, 12};
    int n = sizeof(elements) / sizeof(elements[0]);

    HashTable hashTable(7);

    for (auto element : elements)
        hashTable.insert_item(element);

    hashTable.delete_item(12);
    hashTable.display();

    return 0;
}
