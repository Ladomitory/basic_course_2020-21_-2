#include <iostream>

using namespace std;

struct list
{
    int value;
    struct list* next = NULL;
};

typedef struct Queue
{
    struct list* first = NULL;
    struct list* end = NULL;
} queue;

queue* create()
{
    queue* n = (queue*) malloc(sizeof(queue));
    return n;
}

void makenull(queue* q)
{
    while (q->first)
    {
        struct list* l = q->first;
        q->first = q->first->next;
        free(l);
    }
    free(q->end);
    return;
}

void inqueue(queue* q, int value)
{
    struct list* n = (struct list*) malloc(sizeof(struct list));
    n->value = value;
    q->end->next = n;
    return;
}

int outqueue(queue* q)
{
    if (q->first)
    {
        int a = q->first->value;
        struct list* l = q->first;
        q->first = q->first->next;
        free(l);
        return a;
    }
    else
        return NAN;
    
}

int first(queue* q)
{
    if (q->first)
        return q->first->value;
    else
        return NAN;
    
}

bool empty(queue* q)
{
    return (q->first == NULL);
}

int main()
{
    return 0;
}