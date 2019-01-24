// 定义类 X，Y，Z，函数 h(X *)，满足：
// 类 X 有私有成员 i，Y 的成员函数 g(X *) 是 X 的友元函数，实现对 X 的成员 i 加 1；
// 类 Z 是类 X 的友元类，其成员函数 f(X *) 实现对 X 的成员 i 加 5；
// 函数 h(X *) 是 X 的友元函数，实现对 X 的成员 i 加 10。
// 在一个文件中定义和实现类，在另一个文件中实现 main() 函数。 // 这里就直接写在一个文件里了hhh

#ifndef MY_X_Y_Z_H
#define MY_X_Y_Z_H

class X;
class Y {
public: 
    void g(X * x);
};

class X {
public: 
    X(int i): i(i) {
    }
    ~X(){}
    friend void Y :: g(X *);
    friend class Z;
    friend void h(X *);
    void geti();
private: 
    int i;
};

void Y :: g(X * x) {
    x->i += 1;
}

class Z {
public: 
    void f(X * x) {
        x->i += 5;
    }
};

void h(X * x) {
    x->i += 10;
}

#endif

#include <iostream>
using namespace std;

void X :: geti() {
    cout<<i<<endl;
}

int main()
{
    X x(0);
    Y y;
    Z z;
    y.g(&x);
    cout<<"函数g调用后x的属性为："; // 1
    x.geti();
    z.f(&x);
    cout<<"函数f调用后x的属性为："; // 6
    x.geti();
    h(&x);
    cout<<"函数h调用后x的属性为："; // 16
    x.geti();
}