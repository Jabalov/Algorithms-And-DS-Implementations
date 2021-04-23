#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};

void create(struct Sparse *s)
{
    int i;
    printf("Enter Dimensions:\n");
    scanf("%d%d", &s->m, &s->n);
    printf("Number of non-zero Elements:\n");
    scanf("%d", &s->num);

    s->ele = (struct Element *)malloc(s->num * sizeof(struct Element));

    printf("Enter non-zero Elements");
    for (i = 0; i < s->num; i++)
        scanf("%d%d%d", &s->ele[i].i, &s->ele[i].j, &s->ele[i].x);
}

void display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 0; i < s.m; i++)
    {
        for (j = 0; j < s.n; j++)
        {
            if (i == s.ele[k].i && j == s.ele[k].j)
                printf("%d ", s.ele[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    int i, j, k;
    i = j = k = 0;
    struct Sparse *s3;

    if (s1->m != s2->m || s1->n != s2->n)
        return NULL;

    s3 = (struct Sparse *)malloc(sizeof(struct Sparse));
    s3->ele = (struct Element *)malloc(sizeof(struct Element) * (s1->num + s2->num));

    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            s3->ele[k++] = s1->ele[i++];

        else if (s1->ele[i].i > s2->ele[j].i)
            s3->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                s3->ele[k++] = s1->ele[i++];

            else if (s1->ele[i].j > s2->ele[j].j)
                s3->ele[k++] = s2->ele[j++];

            else
                s3->ele[k] = s1->ele[i],
                s3->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
        }
    }

    for (; i < s1->num; i++)
        s3->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        s3->ele[k++] = s2->ele[j];

    s3->m = s1->m;
    s3->n = s1->n;
    s3->num = k;

    return s3;
}

int main()
{
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);

    printf("First Matrix\n");
    display(s1);

    printf("Second Matrix\n");
    display(s2);

    printf("Sum Matrix\n");
    display(*s3);

    return 0;
}