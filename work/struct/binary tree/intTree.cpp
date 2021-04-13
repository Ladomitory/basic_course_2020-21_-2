#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
    int data;
    struct node* left = NULL;
    struct node* right = NULL;
} tree;

tree* push(tree* root, int data)
{
    if (!root)
    {
        root = (tree*) malloc(sizeof(tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
        root->left = push(root->left, data);
    else if (data > root->data)
        root->right = push(root->right, data);
    return root;
}

void print_infix(tree* root)
{
    if (!root)
        return;
    print_infix(root->left);
    cout << root->data << endl;
    print_infix(root->right);
    return;
}

void free_tree(tree* root)
{
    if (!root)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
    return;
}

int main()
{
    tree* root = NULL;
    int a;
    while (a != 404)
    {
        cout << "new:";
        cin >> a;
        if (a == 404)
            break;
        root = push(root, a);
    }
    cout << "infix" << endl;
    print_infix(root);
    cout << "Free and End" << endl;
    free_tree(root);
    return 0;
}