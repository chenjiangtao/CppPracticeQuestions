// 描述
// 定义 Boat 与 Cat 两个类，二者都有 weight 属性，
// 定义二者的一个友元函数 getTotalWeight()，计算二者的重量和。

#include <iostream>
using namespace std;

class Cat;
class Boat {
    public: 
        Boat(int w): weight(w) {}
        ~Boat() {}
        friend int getTotalWeight(Boat * _b, Cat * _c);
    private: 
        int weight;
};
    
class Cat {
public: 
    Cat(int w): weight(w) {}
    ~Cat() {}
    friend int getTotalWeight(Boat * _b, Cat * _c);
private: 
    int weight;
};

int getTotalWeight(Boat * _b, Cat * _c) {
    return _b->weight + _c->weight;
}

int main()
{
    Boat b(10);
    Cat c(5);
    cout<<"The total weight is: "<<getTotalWeight(&b, &c)<<endl; // 15
    return 0;
}