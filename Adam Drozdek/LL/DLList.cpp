#include "DLList.h"

template <class T>
void DoublyLinkedList<T>::addToDLLHead(const T &el)
{
    if (head != 0)
    {
        head = new DLLNode<T>(el, head, 0);
        head->next->prev = head;
    }
    else
        head = tail = new DLLNode<T>(el);
}

template <class T>
void DoublyLinkedList<T>::addToDLLTail(const T &el)
{
    if (tail != 0)
    {
        tail = new DLLNode<T>(el, 0, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new DLLNode<T>(el);
}

template <class T>
T DoublyLinkedList<T>::deleteFromDLLHead()
{
    T el = head->info;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = 0;
    }
    return el;
}

template <class T>
T DoublyLinkedList<T>::deleteFromDLLTail()
{
    T el = tail->info;
    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    { // if more than one DLLNode in the list;
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}

template <class T>
T *DoublyLinkedList<T>::find(const T &el) const
{
    DLLNode<T> *tmp = head;
    for (; tmp != 0 && !(tmp->info == el); // overloaded ==
         tmp = tmp->next)
        ;
    if (tmp == 0)
        return 0;
    else
        return &tmp->info;
}

template <class T>
T &DoublyLinkedList<T>::firstEl()
{
    return head->info;
}

template <class T>
void DoublyLinkedList<T>::clear()
{
    for (DLLNode<T> *tmp; head != 0;)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}
