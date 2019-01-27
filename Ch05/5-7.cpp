// 描述
// 定义一个 Cat 类，拥有静态数据成员 numOfCats，记录 Cat 的个体数目；静态成员函数 getNumOfCats()，存取 numOfCats。
// 设计程序测试这个类，体会静态数据成员和静态成员函数的用法。


#include <iostream>
using namespace std;

class Cat {
public: 
    Cat(int n): n(n) {
        numOfCats++;
        cout<<"Cat constructor..."<<n<<endl;
    }
    ~Cat() {
        numOfCats--;
        cout<<"Cat destructor..."<<n<<endl;
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
        cout<<"numOfCats = "<<c[i]->getNumOfCats()<<endl; 
    }
    cout<<endl;
    for (int i = 4; i >= 0; i--) {
        delete c[i];
        cout<<"numOfCats = "<<Cat :: getNumOfCats()<<endl; 
    }
    return 0;
}

// 输出
// Cat constructor...0
// numOfCats = 1
// Cat constructor...1
// numOfCats = 2
// Cat constructor...2
// numOfCats = 3
// Cat constructor...3
// numOfCats = 4
// Cat constructor...4
// numOfCats = 5

// Cat destructor...4
// numOfCats = 4
// Cat destructor...3
// numOfCats = 3
// Cat destructor...2
// numOfCats = 2
// Cat destructor...1
// numOfCats = 1
// Cat destructor...0
// numOfCats = 0