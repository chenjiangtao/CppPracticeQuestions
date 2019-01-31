// 描述
// insertOrder 通过对从本章的链表类模板 LinkedList 进行组合，编写有序链表类模板 OrderList，添加成员函数 insert 实现链表元素的有序（递增）插入，
// 声明两个 int 类型有序链表 a 和 b，分别插入 5 个元素，然后把 b 中的元素插入 a 中。

#ifndef _ORDERLIST_H
#define _ORDERLIST_H

#include <iostream>

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

template<typename T> 
class OrderList {
public: 
    Node<T> *head;
    int size;
public: 
    OrderList();
    ~OrderList();
    void insert(const T &item);
    int getSize();
    void print();
};

template<typename T> 
OrderList<T>::OrderList():size(0) {
    head = new Node<T>();
    head->next = NULL;
}

template<typename T> 
OrderList<T>::~OrderList() {
    Node<T> *i = head;
    Node<T> *j;
    while(i) {
        j = i;
        i = i->next;
        delete j;
    }
    head = NULL;
}

template<typename T> 
void OrderList<T>::insert(const T &item) {
    if(head->next == NULL) {
        Node<T> *node = new Node<T>(item);
        head->next = node;
        node->next = NULL;
    }
    else {
        Node<T> *node = new Node<T>(item);
        Node<T> *i = head->next;
        Node<T> *j = head;
        while(i && i->data < item) {
            i = i->next;
            j = j->next;
        }
        j->next = node;
        node->next = i;
    }
    size++;
}

template<typename T> 
int OrderList<T>::getSize() {
    return size;
}

template<typename T> 
void OrderList<T>::print() {
    std::cout<<"head ";
    for(Node<T> *i = head->next; i; i = i->next) {
        std::cout<<"-> "<<i->data<<" ";
    }
    std::cout<<std::endl;
}

#endif

using namespace std;

int main() 
{
    OrderList<int> a;
    OrderList<int> b;
    int item;
    cout<<"Please input 5 numbers for A: ";
    for(int i = 0; i < 5; i++) {
        cin>>item;
        a.insert(item);
    }
    cout<<"Please input 5 numbers for B: ";
    for(int i = 0; i < 5; i++) {
        cin>>item;
        b.insert(item);
    }
    cout<<"OrderList A: ";
    a.print();
    cout<<"OrderList B: ";
    b.print();
    for(Node<int> *i = b.head->next; i; i = i->next) {
        a.insert(i->data);
    }
    cout<<"OrderList A after combining B: ";
    a.print();
    return 0;
}

// 输入
// Please input 5 numbers for A: 1 3 7 6 5
// Please input 5 numbers for B: 2 6 8 5 4
// 输出
// OrderList A: head -> 1 -> 3 -> 5 -> 6 -> 7 
// OrderList B: head -> 2 -> 4 -> 5 -> 6 -> 8 
// OrderList A after combining B: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 6 -> 7 -> 8 