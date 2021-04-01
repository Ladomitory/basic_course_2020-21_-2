#include <iostream>
#include <string>

using namespace std;

class infix_tree
{
    private:
        struct node
        {
            string str = "\0";
            struct node *left = NULL;
            struct node *right = NULL;
        };
        struct node *root;
    public:
        infix_tree ();
        
        void push(string str)
        {
            if (this->empty())
            {
                struct node * n /*new*/ = (node*) malloc(sizeof(node));
                n->str = str;
                this->root = n;  
            }
            struct node * curr /*current*/ = this->root;
            struct node * n /*new*/ = (node*) malloc(sizeof(node));
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

        bool empty()
        {
            return (this->root == NULL);
        }
};