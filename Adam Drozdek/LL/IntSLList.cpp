#include <iostream>
#include "IntSLList.h"

void IntSLList::addToHead(int el)
{
    head = new IntSLLNode(el, head);
    if (tail == 0)
        tail = head;
}

void IntSLList::addToTail(int el)
{
    if (tail != 0)
    {
        tail->next = new IntSLLNode(el);
        tail = tail->next;
    }
    else
        head = tail = new IntSLLNode(el);
}

int IntSLList::deleteFromHead()
{
    int el = head->info;
    IntSLLNode *temp = head;

    if (head == tail)
        head = tail = 0;
    else
        head = head->next;

    delete temp;
    return el;
}

int IntSLList::deleteFromTail()
{
    int el = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }

    else
    {
        IntSLLNode *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            ;
        delete tail;
        tail = tmp;
        tail->next = 0;
    }
    return el;
}

void IntSLList::deleteNode(int el)
{
    if (head != 0)
    {
        if (head == tail && head->info == el)
        {
            delete head;
            head = tail = 0;
        }
        else if (el == head->info)
        {
            IntSLLNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            IntSLLNode *prev, *tmp;

            for (prev = head, tmp = head->next; (tmp != 0) && !(tmp->info != el); prev = prev->next, tmp = tmp->next)
                ;

            if (tmp != 0)
            {
                prev->next = tmp->next;
                if (tmp == tail)
                    tail = prev;
                delete tmp;
            }
        }
    }
}