#include <iostream>

using namespace std;

struct list
{
    int data;
    struct list* next = NULL;
};
typedef struct Queue
{
    struct list* first = NULL;
    struct list* last = NULL;
} queue;

queue* create()
{
    queue* n /*new*/ = (queue*) malloc(sizeof(queue));
    n->first = NULL;
    n->last = NULL;
    return n;
}

void makenull(queue* q)
{
    while (q->first != NULL)
    {
        struct list* l = q->first;
        q->first = q->first->next;
        free(l);
    }
    free(q->last);
    return;
}

void inqueue(queue* q, int value)
{
    struct list* n = (struct list*) malloc(sizeof(struct list));
    n->data = value;
    n->next = NULL;
    if (q->last != NULL)
    {
        q->last->next = n;
        q->last = q->last->next;
    }
    else
    {
        q->first = n;
        q->last = n;
    }
    return;
}

int outqueue(queue* q)
{
    if (q->first)
    {
        int a = q->first->data;
        struct list* l = q->first;
        if (q->first != q->last)
            q->first = q->first->next;
        free(l);
        return a;
    }
    else
        return -1;
    
}

int first(queue* q)
{
    if (q->first)
        return q->first->data;
    else
        return -1;
}

bool empty(queue* q)
{
    return (q->first == NULL);
}

int main()
{
    queue* q = create();
    int command;
    cin >> command;
    while (command != 0)
    {
        if (command == 1)
        {
            int a;
            cin >> a;
            inqueue(q, a);
        }
        else if (command == -1)
        {
            cout << first(q) << endl;
        }
        else //command == -2
        {
            cout << outqueue(q) << endl;
        }
        cin >> command;
    }
    makenull(q);
    return 0;
}