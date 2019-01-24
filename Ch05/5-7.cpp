// 描述
// 定义一个 Cat 类，拥有静态数据成员 numOfCats，记录 Cat 的个体数目；静态成员函数 getNumOfCats()，存取 numOfCats。
// 设计程序测试这个类，体会静态数据成员和静态成员函数的用法。


#include <iostream>
using namespace std;

class Cat {
public: 
    Cat(int n): n(n) {
        numOfCats++;
    }
    ~Cat() {
        numOfCats--;
    }
    static int getNumOfCats() { // 静态成员函数
        return  numOfCats; // 'static' can only be specified inside the class definition
    }
private:
    int n;
    static int numOfCats; // 静态数据成员
};

int Cat :: numOfCats = 0;

int main()
{
    Cat *c[5];
    for (int i = 0; i < 5; i++) {
        c[i] = new Cat(i);
        cout<<Cat(i).getNumOfCats()<<" "; // 2 3 4 5 6
    }
    cout<<endl;
    for (int i = 4; i >= 0; i--) {
        delete c[i];
        cout<<Cat :: getNumOfCats()<<" "; // 4 3 2 1 0
    }
    return 0;
}