#include <iostream>
#include <string>

using namespace std;

typedef struct node
{
    string data;
    struct node* left = NULL;
    struct node* right = NULL;
} tree;

tree* push(tree* root, string data)
{
    if (!root)
    {
        root = (tree*) malloc(sizeof(tree));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (data < root->data)
    {
        root = push(root->left, data);
    }
    else if (data > root->data)
    {
        root = push(root->right, data);
    }
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
    string a;
    while (a != "0995")
    {
        cout << "New elment:";
        cin >> a;
        if (a == "0995")
            break;
        root = push(root, a);
    }
    cout << "infix" << endl;
    print_infix(root);

    cout << "Free Data"<< endl;
    free_tree(root); 
    cout << "End Work" << endl;
    return 0;
}