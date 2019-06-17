#include "list.h"

class LinkedList
{
public:
    Node * start;
    LinkedList()
    {
        start = new Node(-1);
    }
    void addBack(Node * node)
    {
        Node * x = start;
        while (x->next != NULL)
        {
            x = x->next;
        }
        x->next = node;
    }
    void show()
    {
        for (Node * x = start->next; x != NULL; x = x->next)
        {
            cout<<x->value<<endl;
        }
    }
};

inline void initAB(LinkedList A, LinkedList  B)
{
    for (int i = 1; i <= 5; i ++)
    {
        A.addBack(new Node(i));
        B.addBack(new Node(i + 5));
    }
}

inline void insertB2A(LinkedList A, LinkedList B)
{
    A.addBack(B.start);
}
int main()
{
    LinkedList A,B;
    initAB(A, B);
    A.show();
    B.show();
    insertB2A(A, B);
    A.show();
    return 0;
}