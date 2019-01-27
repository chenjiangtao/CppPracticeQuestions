// 描述
// 定义一个基类 BaseClass，从它派生出类 DerivedClass，BaseClass 有成员函数 fn1()，fn2()，DerivedClass 也有成员函数 fn1()，fn2()，
// 在主函数中声明一个 DerivedClass 的对象，分别用 DerivedClass 的对象以及 BaseClass 和 DerivedClass 的指针来调用 fn1()，fn2()，观察运行结果。

#include <iostream>
using  namespace std;

class BaseClass {
public: 
    BaseClass() {
        cout<<"BaseClass constructor..."<<endl;
    }
    virtual ~BaseClass() {
        cout<<"BaseClass destructor..."<<endl;
    }
    virtual void fn1() {
        cout<<"call BaseClass fn1..."<<endl;
    }
    virtual void fn2() {
        cout<<"call BaseClass fn2..."<<endl;
    }
};

class DerivedClass : public BaseClass {
public: 
    DerivedClass() : BaseClass() {
        cout<<"DerivedClass constructor..."<<endl;
    }
    ~DerivedClass() {
        cout<<"DerivedClass destructor..."<<endl;
    }
    void fn1() {
        cout<<"call DerivedClass fn1..."<<endl;
    }
    void fn2() {
        cout<<"call DerivedClass fn2..."<<endl;
    }
};

int main()
{
    cout<<"obj: "<<endl;
    DerivedClass obj;
    obj.BaseClass :: fn1();
    obj.BaseClass :: fn2();
    obj.fn1();
    obj.fn2();
    cout<<endl;

    cout<<"*bp: "<<endl;
    BaseClass *bp;
    bp = new BaseClass();
    bp->fn1();
    bp->fn2();
    delete bp;
    cout<<endl;

    cout<<"*dp: "<<endl;
    DerivedClass *dp;
    dp = new DerivedClass();
    dp->BaseClass :: fn1();
    dp->BaseClass :: fn2();
    dp->fn1();
    dp->fn2();
    delete dp;
    cout<<endl;
}

// 本题输出
// obj: 
// BaseClass constructor...
// DerivedClass constructor...
// call BaseClass fn1...
// call BaseClass fn2...
// call DerivedClass fn1...
// call DerivedClass fn2...

// *bp: 
// BaseClass constructor...
// call BaseClass fn1...
// call BaseClass fn2...
// BaseClass destructor...

// *dp: 
// BaseClass constructor...
// DerivedClass constructor...
// call BaseClass fn1...
// call BaseClass fn2...
// call DerivedClass fn1...
// call DerivedClass fn2...
// DerivedClass destructor...
// BaseClass destructor...

// DerivedClass destructor...
// BaseClass destructor...