#include <iostream>
#include <string>
#include <ctype.h> //isdigit
#include <climits>

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
        return INT_MIN; 

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
        return INT_MIN;
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

string infix_to_postfix(string s)
{
    string ans;
    Stack *st = create();
    string a;
    for (int i = 0; i < s.length(); ++i)
        if (isdigit(s[i]))
            ans.push_back(s[i]);
        else if (s[i] == '(')
            push(st, s[i]);
        else if (s[i] == ')')   
        {
            while (!empty(st) && top(st) != '(')
                ans.push_back(pop(st));
            a = pop(st);
        }
        else
        {
            if (s[i] == '*' || s[i] == '/')
                while (!empty(st) && top(st) == '*' && top(st) == '/')
                    ans.push_back(pop(st));  
            else if (s[i] == '+' || s[i] == '-')
                while (!empty(st) && top(st) != '=' && top(st) != '(')
                    ans.push_back(pop(st));
            else
                while (!empty(st) && top(st) != '(')
                    ans.push_back(pop(st));
            push(st, s[i]);
        }


    while (!empty(st))
        ans.push_back(pop(st));
    return ans;
}

int operate(int a, int b, char o)
{
    int ans;
    if (o == '+')
        ans = a + b;
    else if (o = '-')
        ans = a - b;
    else if (o = '*')
        ans = a * b;
    else if (o = '/')
        ans = a / b;

    return ans;
}

int postfix(string s)
{
    Stack *st = create();
    int a, b;
    for (int i = 0; i < s.length(); ++i)
        if (isdigit(s[i]))
            push(st, s[i]);
        else
        {
            b = pop(st);
            a = pop(st);
            push(st, operate(a, b, s[i]));
        }
    return pop(st);   
}

int main()
{
    string is;
    cin >> is;
    string ps;
    ps = infix_to_postfix(is);
    cout << ps << endl;
    int ans = postfix(ps);
    cout << ans << endl;

    return 0;
}