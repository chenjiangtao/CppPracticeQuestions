// 描述
// 请编写一个计数器 Counter 类，对其重载运算符 + 。

#include <iostream>
using namespace std;

class Counter {
public: 
    Counter() : n(0) {}
    Counter(unsigned n) : n(n) {}
    ~Counter() {}
    Counter operator + (const Counter &_y);
    unsigned retrieve();
private: 
    unsigned n;
};

Counter Counter :: operator + (const Counter & _y) {
    return Counter(n + _y.n);
}

unsigned Counter :: retrieve() {
    return n;
}

int main()
{
    Counter a(2), b(4), c;
    c = a + b;
    cout<<a.retrieve()<<" + "<<b.retrieve()<<" = "<<c.retrieve()<<endl;
    return 0;
}
