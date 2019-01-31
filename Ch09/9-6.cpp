// 描述
// insertOrder 通过对从本章的链表类模板 LinkedList 进行组合，编写有序链表类模板 OrderList，添加成员函数 insert 实现链表元素的有序（递增）插入
// 声明两个 int 类型有序链表 a 和 b，分别插入 5 个元素，然后把 b 中的元素插入 a 中。

#include <iostream>

#ifndef _ORDERLIST_H
#define _ORDERLIST_H

// create class for Node
template<typename T> 
class Node {
public: 
    T data;
    Node<T> *next;
public: 
    Node();
    Node(const T &val);
    ~Node(){}
};

template<typename T> 
Node<T>::Node() {
    next = this;
}

template<typename T> 
Node<T>::Node(const T &val) {
    next = this;
    data = val;
}

// create class for OrderList
template<typename T> 
class OrderList {
public: 
    Node<T> nodes[1000];
    Node<T> *head();
    int size;
public: 
    // constructions
    OrderList();
    ~OrderList();

    // modifiers
    void insert(const T &item);
    void insert(Node<T> node);

    // operations
    void print();
};

template<typename T> 
OrderList<T>::OrderList():size(0) {
    head()->next = NULL;
}

template<typename T> 
OrderList<T>::~OrderList() {
    // for(Node<T> *i = head(); i; i = i->next) {
    //     delete i;
    // }
}

template<typename T> 
void OrderList<T>::insert(const T &item) {
    if(head()->next == NULL) {
        head()->next = &nodes[0];
        nodes[0].next = NULL;
    }
    else {
        Node<T> *i = head()->next;
        Node<T> *j = head();
        while(i && i->data < item) {
            i = i->next;
            j = j->next;
        }
        j->next = &nodes[size];
        nodes[size].next = i;
    }
    size++;
}

template<typename T> 
void OrderList<T>::insert(Node<T> node) {
    if(head()->next == NULL) {
        nodes[0] = node;
        head()->next = &node;
        node.next = NULL;
    }
    else {
        nodes[size] = node;
        Node<T> *i = head()->next;
        Node<T> *j = head();
        while(i && i->data < node.data) {
            i = i->next;
            j = j->next;
        }
        j->next = &node;
        node.next = i;
    }
    size++;
}

template<typename T> 
void OrderList<T>::print() {
    std::cout<<"head ";
    for(Node<T> *i = head()->next; i; i = i->next) {
        std::cout<<"-> "<<i->data<<" ";
    }
    std::cout<<std::endl;
}

#endif

int main() 
{
    OrderList<int> a;
    OrderList<int> b;
    int item;
    std::cout<<"Please input 5 numbers for A: ";
    for(int i = 0; i < 5; i++) {
        std::cin>>item;
        a.insert(item);
    }
    std::cout<<"Please input 5 numbers for B: ";
    for(int i = 0; i < 5; i++) {
        std::cin>>item;
        b.insert(item);
    }
    std::cout<<"OrderList A: ";
    a.print();
    std::cout<<"OrderList B: ";
    b.print();
    for(int i = 0; i < b.size; i++) {
        a.insert(b.nodes[i].data);
    }
    std::cout<<"OrderList A after combining B: ";
    a.print();
    return 0;
}