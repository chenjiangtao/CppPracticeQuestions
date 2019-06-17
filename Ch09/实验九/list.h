#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Node
{
public:
    int value;
    Node * next;
    Node(){}
    Node(int v) {value = v; next=NULL;}
    void add(Node * node)
    {
        this->next = node;
    }
};