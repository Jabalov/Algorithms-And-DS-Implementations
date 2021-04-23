#include <bits/stdc++.h>

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node()
        : data{}, next{nullptr} {}
    Node(T key)
        : data{key}, next{nullptr} {}
};

template <class T>
class stack
{
    Node<T> *Top;
    int length;

public:
    stack()
    {
        Top = nullptr;
        length = 0;
    }

    stack(std::vector<T> arr)
    {
        int n = static_cast<int>(arr.size());
        length = n;
        if (n == 0)
        {
            Top = nullptr;
        }
        else
        {
            Top = new Node<T>(arr[0]);

            Node<T> *new_node;
            for (int i = 1; i < n; i++)
            {
                new_node = new Node<T>(arr[i]);
                new_node->next = Top;
                Top = new_node;
            }
        }
    }

    ~stack()
    {
        Node<T> *p = Top;
        while (Top)
        {
            Top = Top->next;
            delete p;
            p = Top;
        }
        length = 0;
    }
    void push(T data);
    void pop();
    T top()
    {
        T temp{};
        return Top ? Top->data : temp;
    }
    bool empty() { return Top == nullptr; }
    bool full();
    int size() { return length; }
    void peep(int index);
    void display();
};

template <class T>
void stack<T>::push(T data)
{
    Node<T> *temp{Top}, *new_node{new Node<T>(data)};
    if (new_node == nullptr)
    {
        std::cout << "Stack Overflow\n";
        return;
    }
    if (temp == nullptr)
    {
        Top = new_node;
        length = 1;
        return;
    }
    else
    {
        new_node->next = Top;
        Top = new_node;
        length += 1;
        return;
    }
}

template <class T>
void stack<T>::pop()
{
    if (Top == nullptr)
    {
        std::cout << "Stack underflow\n";
        return;
    }
    Node<T> *t{Top};
    Top = Top->next;
    delete t;
    length -= 1;
}

template <class T>
bool stack<T>::full()
{
    Node<T> *t = new Node<T>();
    if (t == nullptr)
        return true;
    free(t);
    return false;
}

template <class T>
void stack<T>::peep(int index)
{
    if (length - index <= 0)
    {
        std::cout << "Invalid index\n";
        return;
    }
    Node<T> *temp{Top};
    for (int i = 0; i < index; i++)
        temp = temp->next;

    std::cout << "Element at index " << index << " is " << temp->data << "\n";
}

template <class T>
void stack<T>::display()
{
    Node<T> *temp{Top};
    while (temp)
    {
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
}

int in_precedence(char ch)
{
    std::map<char, int> prec;
    prec['+'] = 2;
    prec['-'] = 2;
    prec['*'] = 4;
    prec['/'] = 4;
    prec['^'] = 5;
    prec['('] = 0;
    //prec[')'] = 4;

    return prec[ch];
}

int out_precedence(char ch)
{
    std::map<char, int> prec;
    prec['+'] = 1;
    prec['-'] = 1;
    prec['*'] = 3;
    prec['/'] = 3;
    prec['^'] = 6;
    prec['('] = 7;
    prec[')'] = -1;

    return prec[ch];
}

bool isOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')')
        return false;
    else
        return true;
}

std::string infix_to_postfix(std::string infix)
{
    std::string postfix;
    stack<char> s1;
    int i = 0;
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix.push_back(infix[i++]);
        else
        {
            if (out_precedence(infix[i]) > in_precedence(s1.top()))
                s1.push(infix[i++]);
            else
            {
                if (infix[i] == ')')
                {
                    i++;
                    postfix.push_back(s1.top());
                    s1.pop();
                }
                else
                {
                    if (s1.top() != '(')
                        postfix.push_back(s1.top());
                    s1.pop();
                }
            }
        }
    }
    while (!s1.empty())
    {
        if (s1.top() != '(')
            postfix.push_back(s1.top());
        s1.pop();
    }
    return postfix;
}

int main()
{
    std::string str{"((a+b)*c)-d^e^f"};
    std::cout << infix_to_postfix(str) << "\n";
}