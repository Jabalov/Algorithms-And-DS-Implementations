#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Node
{
private:
    /* data */
public:
    string Key;
    T Value;
    Node *Next;

    Node(string Key, T Value, Node *_Next = NULL)
    {
        this->Key = Key;
        this->Value = Value;
    }

    ~Node()
    {
        delete Next;
    }
};

template <typename T>
class HashMap
{
private:
    Node<T> **Buckets;
    int Count, NumOfBuckets;

    int HashFunction(string key)
    {
        int Code = 0, Base = 1, P = 37;

        for (int i = key.size() - 1; i >= 0; i--)
        {
            Code += key[i] * Base;
            Base *= P;
            Code %= NumOfBuckets;
            base % -NumOfBuckets;
        }

        return Code % NumOfBuckets
    }

public:
    HashMap()
    {
        Count = 0, NumOfBuckets = 15;
        Buckets = new Node *[NumOfBuckets];

        for (int i = 0; i < NumOfBuckets; i++)
            Buckets[i] = NULL;
    }

    ~HashMap()
    {
        for (int i = 0; i < NumOfBuckets; i++)
            delete Buckets[i];

        delete[] Buckets;
    }

    int Size()
    {
        return Count;
    }

    void Insert(string key, T value)
    {
        int index = HashFunction(key);
        Node<T> *LastNode = Buckets[index];

        while (LastNode != null)
        {
            if (LastNode->Key == key)
                LastNode->Value = value, return;

            LastNode = LastNode->Next;
        }

        auto *NewNode = new Node<T>(key, value);
        // NewNode->Next = Buckets[index];
        // Buckets[index] = NewNode;
        LastNode->Next = NewNode;
        Count++;
    }
};
