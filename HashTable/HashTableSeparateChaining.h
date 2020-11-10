#ifndef D_HASHTABLESEPARATECHAINING_H
#define D_HASHTABLESEPARATECHAINING_H

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>

#include <sstream>
#include <memory>
#include <iostream>
#include <cmath>

class Bucket
{
private:
    int key, value;
    Bucket *next;

public:
    Bucket(int _key, int _value, Bucket *_next = nullptr)
    {
        this->key = _key;
        this->value = _value;
        this->next = _next;
    }

    int GetKey()
    {
        return key;
    }

    int GetValue()
    {
        return value;
    }

    void SetValue(int value)
    {
        this->value = value;
    }

    Bucket *GetNext()
    {
        return next;
    }

    void SetNext(Bucket *next)
    {
        this->next = next;
    }
};

const int SIZE = 128;

class HashMap
{
private:
    Bucket **HashTable;

public:
    HashMap()
    {
        HashTable = new Bucket *[SIZE];
        for (int i = 0; i < SIZE; i++)
            HashTable[i] = nullptr;
    }

    ~HashMap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (HashTable[i] != nullptr)
            {
                Bucket *row = HashTable[i], *auxilary = nullptr;

                while (row != nullptr)
                {
                    auxilary = row;
                    row = row->GetNext();
                    delete auxilary;
                }
            }
        }
        delete[] HashTable;
    }

    void push(int key, int value)
    {
        int hash = key % SIZE;

        if (HashTable[hash] == nullptr)
            HashTable[hash] = new Bucket(key, value);

        else
        {
            Bucket *row = HashTable[hash], *last = row;

            while (last->GetNext() != NULL)
                last = last->GetNext();

            last->SetNext(new Bucket(key, value));
        }
    }
};

#endif