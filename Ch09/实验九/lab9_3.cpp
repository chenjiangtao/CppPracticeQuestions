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

class Queue
{
public:
    LinkedList lst;
    Node * head; 
    Node * tail;
    Queue()
    {
        lst = LinkedList();
        head = lst.start;
        tail = head;
    }
    bool pop_front()
    {
        if (head == tail) return false;
        head = head->next;
        return true;
    }
    void addNode(Node * node)
    {
        lst.addBack(node);
        tail = node;
    }
};