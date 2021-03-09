#include <iostream>

using namespace std;

class tree
{
    private:
        struct node
        {
            int value;
            struct node *left = NULL;
            struct node *right = NULL;
        };
        struct node *root;
    public:
        void a();
}