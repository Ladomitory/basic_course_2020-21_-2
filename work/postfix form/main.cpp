#include <iostream>
#include <string>
#include <ctype.h>

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
        int a = S->top->value;
        struct list* l = S->top;
        S->top = S->top->next;
        free(l);
        return a;
    }
    else
        return NAN;
}

void push(Stack *S, int x)
{
    struct list *l = (struct list*)malloc(sizeof(struct list));
    l->value = x;
    l->next = S->top;
    S->top = l;
}

bool empty(Stack *S)
{
    return (S->top == NULL);
}

string infix_postfix(string s)
{
    string ans;
    Stack *st;
    string a;
    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
            ans.push_back(s[i]);
        else if (s[i] == '(')
            push(st, s[i]);
        else if (s[i] == ')')
        {
            while (top(st) != '(')
                ans.push_back(pop(st));
            a = pop(st);
        }
        else
            

            
    }
}

int postfix(string s)
{

}

int main()
{
    string s;
    cin >> s;


    return 0;
}