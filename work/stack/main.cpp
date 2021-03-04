#include <iostream>

using namespace std;

struct list 
{ 
    int value;
    struct list* next;
};

typedef struct stack {struct list *top;} Stack;

void makenull(Stack *S)
{
    struct list* l;
    while (S->top)
    {
        l = S->top;
        S->top = l->next;
        free(l);
    }
}

Stack * create()
{
    Stack *S;
    S = (Stack*)malloc(sizeof(Stack));
    S->top = NULL;
    return S;
}

int top(Stack *S)
{
    if (S->top)
        return S->top->value;
    else
        return NAN; 
}

int pop(Stack *S)
{
    if (S->top)
    {
        
    }
}

int main()
{
    return 0;
}