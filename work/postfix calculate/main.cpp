#include <iostream>
#include <string>
#include <ctype.h> //isdigit

using namespace std;

struct list 
{ 
    double value;
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

double top(Stack *S)
{
    if (S->top)
        return S->top->value;
    else
        return 0; 

}

double pop(Stack *S)
{
    if (S->top)
    {
        double a = S->top->value;
        struct list* l = S->top;
        S->top = S->top->next;
        free(l);
        return a;
    }
    else
        return 0;
}

void push(Stack *S, double x)
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



double calculate(string str)
{
    Stack *st = create();
    bool f = true;
    string a = "\0";
    for (int i = 0; i < str.length(); ++i)
    {
        if (isdigit(str[i]) && f)
            a.push_back(str[i]);
        else if (isdigit(str[i]) && !f)
        {
            a = str[i];
        }
        else if (str[i] == ' ' && a != "\0")
        {
            push(st, stoi(a));
            a = "\0";
        }
        else if (str[i] != ' ')
        {
            double y = pop(st);
            double x = pop(st);
            if (str[i] == '+')
                push(st, x + y);
            if (str[i] == '-')
                push(st, x - y);
            if (str[i] == '*')
                push(st, x * y);
            if (str[i] == '/')
                push(st, x / y);
        }
    }
    double ans = pop(st);
    makenull(st);
    free(st);
    return ans;
}

int main()
{
    string ps;
    getline(cin, ps);
    double ans = calculate(ps);
    cout << ans;
    return 0;
}