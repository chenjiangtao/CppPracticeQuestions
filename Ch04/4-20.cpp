// 描述
// 定义一个复数类 Complex，使得下面的代码能够工作：
// Complex c1(3, 5); // 用复数 3 + 5i 初始化 c1
// Complex c2 = 4.5; // 用实数 4.5 初始化c2
// c1.add(c2); // 将 c1 与 c2 相加，结果保存在 c1 中
// c1.show(); // 将 c1 输出（这时的结果应该是 7.5 + 5i）

#include <iostream>
using namespace std;

class Complex {
public: 
    Complex(double r, double i): 
        real(r), image(i) {
    }
    Complex(double r): 
        real(r), image(0) {
    }
    void add(Complex x);
    void show();
private: 
    double real;
    double image;
};

void Complex :: add(Complex x) {
    real += x.real;
    image += x.image;
}

void Complex :: show() {
    cout<<real<<" + "<<image<<"i"<<endl;
}

int main()
{
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
    return 0;
}