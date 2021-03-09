#include <iostream>

using namespace std;

class queue
{
    private:
        struct list
        {
            int value;
            struct list *next = NULL;
        };
        struct list *top = NULL;
        struct list *backtop = NULL;
    public:
        void makenull()
        {
            struct list *l;
            while (this->top)
            {
                l = this->top;
                this->top = this->top->next;
                free(l);
            }
            free(this->backtop);
        }

        int top()
        {
            if (this->top)
                return this->top->value;
            else
                return (int) NAN;
        }

        int pop()
        {
            if (this->top)
            {
                int a = this->top->value;
                struct list *l = this->top;
                if (this->top == this->backtop)
                    this->backtop = this->backtop->next;
                this->top = this->top->next;
                free(l);
                return a;
            }
            else
                return (int) NAN;
        }
        
        void push(int value)
        {
            struct list *n = (struct list*) malloc(sizeof(struct list));
            n->next = NULL;
            n->value = value;
            this->backtop->next = n;
            if (!this->top)
                this->top = this->backtop;
        }

        bool empty()
        {
            return (this->top == NULL);
        }
};

int main()
{
    return 0;
}
