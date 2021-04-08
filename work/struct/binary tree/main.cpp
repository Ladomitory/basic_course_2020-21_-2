#include <iostream>
#include <string>

using namespace std;

struct node
{
    string str = "\0";
    struct node* left = NULL;
    struct node* right = NULL;
};

typedef struct Tree {struct node* root = NULL;} tree;

bool empty(tree* t)
{
    return (t->root == NULL);
}

void push(tree* t, string str)
{
    if (empty(t))
    {
        struct node* n /*new*/ = (node*) malloc(sizeof(node));
        n->str = str;
        t->root = n;
        return;
    }
    struct node* curr /*current*/ = t->root;
    struct node* n /*new*/ = (node*) malloc(sizeof(node));
    n->str = str;
    while (curr)
    {
        if (curr->str > n->str)
        {
            if (curr->right)
                curr = curr->right;
            else
            {
                curr->right = n;
                break;
            } 
        }
        else if (curr->str < n->str)
        {
            if (curr->left)
                curr = curr->left;
            else
            {
                curr->left = n;
                break;
            }
        }
        else //curr->str == n->str
            break;
    }        
    return;
}

void trev(struct node* n)
{
    cout << " a";
    if (n->left != NULL)
        trev(n->left);
    cout << "c";
    cout << n->str << endl;
    if (n->right != NULL)
        trev(n->right);
    return;
}

void treversal(tree* t)
{
    if (empty(t))
    {
        cout << "empty" << endl;
        return;
    }
    trev(t->root);
    return;
}

int main()
{
    tree* t = (tree*)malloc(sizeof(tree));
    t->root = NULL;
    cout << "new:\n";
    string str;
    do {
        cin >> str;
        if (str != "0995")
        { 
            push(t, str);
            str = "\0";
        }
    } while (str != "0995");
    treversal(t);
    free(t);
    return 0;
}