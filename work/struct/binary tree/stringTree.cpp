#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
    string data = "\0";
    struct node* left = NULL;
    struct node* right = NULL;
} tree;

bool empty(tree* root)
{
    return (root == NULL);
}

tree* push(tree* root, string data)
{
    if (empty(root))
    {
        root = (tree*) malloc(sizeof(tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
        root = push(root->left, data);
    else
        root = push(root->right, data);
    return root;
}

void print_infix(tree* root)
{
    if (empty(root))
        return;
    print_infix(root->left);
    cout << root->data << endl;
    print_infix(root->right);
    return;
}

void free_tree(tree* root)
{
    if (empty(root))
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
    return;
}

int main()
{
    
    tree* root = NULL;
    string str;
    while (true)
    {
        cout << "new:";
        cin >> str;
        if (str == "404")
            break;
        push(root, str);
    }
    cout << "infix" << endl;
    print_infix(root);
    cout << "Free Data" << endl;
    free_tree(root);
    cout << "End Work" << endl;
    return 0;
}