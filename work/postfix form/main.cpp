#include <iostream>
#include <string>
#include <ctype.h> //isdigit

using namespace std;

struct list 
{ 
    char value;
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

char top(Stack *S)
{
    if (S->top)
        return S->top->value;
    else
        return '\0'; 

}

char pop(Stack *S)
{
    if (S->top)
    {
        char a = S->top->value;
        struct list* l = S->top;
        S->top = S->top->next;
        free(l);
        return a;
    }
    else
        return '\0';
}

void push(Stack *S, char x)
{
    struct list *l = (struct list*)malloc(sizeof(struct list));
    l->value = x;
    l->next = S->top;
    S->top = l;
    return;
}

bool empty(Stack *S)
{
    return (S->top == NULL);
}

string inf_to_post(string s)
{
    Stack *st = create();
    string ans;
    char a;
    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))
            ans.push_back(s[i]);
        else if (s[i] == '(')
            push(st, s[i]);
        else if (s[i] == ')')   
        {
            while (empty(st) && top(st) != '(')
            while (!empty(st) && top(st) != '(')
                ans.push_back(pop(st));
            a = pop(st);
        }
        else
            if (s[i] == '*' || s[i] == '/')
            {
                while (empty(st) && top(st) == '*' && top(st) == '/')
                    ans.push_back(pop(st));
                push(st, s[i]);                
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (empty(st) && top(st) != '=' && top(st) != '(')
                    ans.push_back(pop(st));
                push(st, s[i]);
        }
    while (!empty(st))
        ans.push_back(pop(st));
    return ans;
}