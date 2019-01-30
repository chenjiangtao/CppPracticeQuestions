// 描述
// 试声明并实现双向链表中使用的结点类 DNode

// dnode.h
#include <iostream>

#ifndef DOUBLEY_LINKED_NODE_CLASS
#define DOUBLEY_LINKED_NODE_CLASS

template<typename T>
class DNode {
public: 
    // 构造函数、复制构造函数、析构函数
    DNode();
    DNode(const T &val);
    ~DNode() {}
    // 链表修改函数
    void insertPrev(DNode<T> *p);
    void insertNext(DNode<T> *p);
    DNode<T> *deleteNode();
    // 获取左侧和右侧结点的地址
    DNode<T> &getPrev();
    DNode<T> &getNext();
    // 输出
    void printNode();
public: 
    T data;
    DNode<T> *prev;
    DNode<T> *next;
};

template<typename T>
DNode<T>::DNode() {
    // 初始化结点，使之指向自身
    prev = next = this;
}

template<typename T>
DNode<T>::DNode(const T &val) {
    data = val;
    prev = next = this;
}

template<typename T> 
void DNode<T>::insertPrev(DNode<T> *p) {
    if(prev == this) { // 最前方的点
        prev = p;
        prev->next = this;
    }
    else {
        prev->next = p;
        p->prev = prev;
        prev = p;
        p->next = this;
    }
}

template<typename T>
void DNode<T>::insertNext(DNode<T> *p) {
    if(next == this) { // 最后方的点
        next = p;
        next->prev = this;
    }
    else {
        next->prev = p;
        p->next = next;
        next = p;
        p->prev = this;
    }
}

template<typename T>
DNode<T> *DNode<T>::deleteNode() {
    if(prev == this) { // 最前方的结点
        next->prev = next;
    }
    else if(next == this) { // 最后方的结点
        prev->next = prev;
    }
    else{
        prev->next = next;
        next->prev = prev;
    }
    return this;
}

template<typename T> 
DNode<T> &DNode<T>::getPrev() {
    return prev;
}

template<typename T> 
DNode<T> &DNode<T>::getNext() {
    return next;
}

template<typename T>
void DNode<T>::printNode() {
    std::cout<<data<<std::endl;
}

#endif