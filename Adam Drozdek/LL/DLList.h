#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

template <class T>
class DLLNode
{
public:
    DLLNode()
    {
        next = prev = 0;
    }
    DLLNode(const T &el, DLLNode<T> *n = 0, DLLNode<T> *p = 0)
    {
        info = el;
        next = n;
        prev = p;
    }

private:
    T info;
    DLLNode<T> *next, *prev;
};

template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = tail = 0;
    }
    void addToDLLTail(const T &);
    T deleteFromDLLTail();
    ~DoublyLinkedList()
    {
        clear();
    }
    bool isEmpty() const
    {
        return head == 0;
    }
    void clear();
    void setToNull()
    {
        head = tail = 0;
    }
    void addToDLLHead(const T &);
    T deleteFromDLLHead();
    T &firstEl();
    T *find(const T &) const;

protected:
    DLLNode<T> *head, *tail;
    friend std::ostream &operator<<(std::ostream &out, const DoublyLinkedList<T> &dll)
    {
        for (DLLNode<T> *tmp = dll.head; tmp != 0; tmp = tmp->next)
            out << tmp->info << ' ';
        return out;
    }
};

#endif
