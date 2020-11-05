#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntSLLNode
{
public:
    int info;
    IntSLLNode *next;

    IntSLLNode()
    {
        next = 0;
    }

    IntSLLNode(int i, IntSLLNode *_next = 0)
    {
        info = i, next = _next;
    }
};

class IntSLList
{
public:
    IntSLList() : head(0), tail(0) {}
    ~IntSLList() {}
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
    void printAll() const;

private:
    IntSLLNode *head, *tail;
};

#endif
