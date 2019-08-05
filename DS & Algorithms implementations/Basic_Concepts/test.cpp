#include <bits\stdc++.h>
#include <stdlib.h>
using namespace std;

struct rect
{
    int len;
    int bred;
};

struct complex
{
    double real;
    double img;
};

int *fun(int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return p;
}

int area(struct rect r1)
{
    return r1.bred * r1.len;
}

void changeLen(struct rect *p, int n)
{
    p->len = n;
}

void swap_byAddress(int *x, int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap_byRef(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

main()
{
    //Arrays
    int m[10];

    //Structures
    struct rect r = {10, 10};
    r.bred = 12;

    //Pointers
    int a = 10;
    int *p;
    p = &a;
    printf("%d", *p); //this will print 10

    int *P1, *P2;
    P1 = (int *)malloc(5 * sizeof(int));
    P2 = new int[5];

    //Reference (nickname)
    int a = 10;
    int &r = a;

    //Pointer to structure
    struct rect re = {10, 5};
    struct rect *po = &re;

    (*po).len = 200;
    po->len = 200;

    //another examble
    struct rect *pointer;
    pointer = (struct rect *)malloc(sizeof(struct rect));
    pointer->len = 10;
    pointer->bred = 10;

    //call by address
    int a = 10, b = 90;
    swap_byAddress(&a, &b);
    //call by reference
    swap_byRef(a, b);
}
