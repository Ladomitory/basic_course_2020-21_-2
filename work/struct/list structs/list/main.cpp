#include <iostream>

using namespace std;

struct list
{
    double value;
    struct list *next = NULL;
};

double value(struct list* l, int k)
{
    if (l == NULL)
        return 0;
    while (k > 0)
    {
        l = l->next;
        k--;
    }
    return l->value;
}

void push(struct list* l, int k, double value) //новый узел перед k
{
    struct list* n = (struct list*) malloc(sizeof(struct list));
    n->value = value;
    if (k == 0)
    {
        n->next = l;
        l = n;
    }
    else
    {
        while (k > 1)
        {
            k--;
            l = l->next;
        }
        n->next = l->next;
        l->next = n;
    }
    return;
}

void del(struct list* l, int k) //исключить k
{
    while (k > 1)
    {
        k--;
        l = l->next;
    }
    struct list* K = l->next;
    l->next = K->next;
    free(K);
    return;
}

struct list* copy(struct list* l)
{
    struct list* n = (struct list*) malloc(sizeof(struct list));
    struct list* m = n;
    m->value = l->value;
    while (l->next != NULL)
    {
        struct list* p = (struct list*) malloc(sizeof(struct list));
        m->next = p;
        m->next->value = l->next->value;
        m = m->next;
        l = l->next;
    }
    return n;
}

int listsize(struct list* l)
{
    int ans = 1;
    while (l->next)
    {
        l = l->next;
        ans++;
    }
    return ans;
}

int key(struct list* l, double value) //Найти в списке узел с заданным значением
{
    int ans = -1, k = 0;
    do
    {
        if (l->value != value)
        {
            k++;
            l = l->next;
        }
        else
        {
            ans = k;
            break;
        }
        
    } while (l->next);
    return ans;
}
/*
Объединить два или более линейных списков в один.

Разбить линейный список на два или более линейных
списков.

Выполнить сортировку в возрастающем порядке по
некоторым значениям полей в узлах.
*/

struct list * merge(struct list *l1, struct list *l2) //слияние сприсков l1 и l2
{
    struct list *al; //ans list
    while (l1->next != NULL || l2->next != NULL)
    {
        if (l1->value >= l2->value)
        {

        }
    }
}