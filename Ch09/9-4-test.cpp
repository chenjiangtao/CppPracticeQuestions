// 描述
// 试声明并实现双向链表中使用的结点类 DNode

#include <iostream>
#include "9-4.h"

int main()
{
    DNode<int> a(5);
    std::cout<<"a: ";
    a.printNode();
    // add b to the next of a: 
    DNode<int> b(6);
    a.insertNext(&b);
    std::cout<<"-- add b --"<<std::endl;
    std::cout<<"a.next = b: ";
    a.next->printNode();
    // add c to the previous of a: 
    DNode<int> c(4);
    a.insertPrev(&c);
    std::cout<<"-- add c --"<<std::endl;
    std::cout<<"a.prev = c: ";
    a.prev->printNode();
    // add d to the previous of c: 
    DNode<int> d(3);
    c.insertPrev(&d);
    std::cout<<"-- add d --"<<std::endl;
    std::cout<<"c.prev = d: ";
    c.prev->printNode();
    // delete c: 
    c.deleteNode();
    std::cout<<"-- delete c --"<<std::endl;
    std::cout<<"a.prev = d: ";
    a.prev->printNode();
    // delete d:
    d.deleteNode();
    std::cout<<"-- delete d --"<<std::endl;
    std::cout<<"a.prev = a: "; 
    a.prev->printNode();
    // delete b:
    b.deleteNode();
    std::cout<<"-- delete b --"<<std::endl;
    std::cout<<"a.prev = a: ";
    a.prev->printNode();
    std::cout<<"a.next = a: ";
    a.next->printNode();
    return 0;
}

// 输出
// a: 5
// -- add b --
// a.next = b: 6
// -- add c --
// a.prev = c: 4
// -- add d --
// c.prev = d: 3
// -- delete c --
// a.prev = d: 3
// -- delete d --
// a.prev = a: 5
// -- delete b --
// a.prev = a: 5
// a.next = a: 5