// 描述
// 定义一个基类 Shape，在此基础上派生出 Rectangle 和 Circle，二者都有 getArea() 函数计算对象的面积。
// 使用 Rectange 类创建一个派生类 Square。

#include <iostream>
using namespace std;

#define PI 3.14

class Shape {
public: 
    Shape() {
        cout<<"新建了一个 Shape 对象"<<endl;
    }
    virtual ~Shape() { // 基类的析构函数需要是一个虚函数，否则 delete 时只释放基类不释放子类，可能存在内在泄漏的问题
        cout<<"回收了一个 Shape 对象"<<endl;
    }
    virtual float getArea() { // 这里的 getArea() 需要是一个虚函数
        return -1;
    }
};

class Rectangle : public Shape {
public: 
    Rectangle(float l, float w) : length(l), width(w) {
        cout<<"新建了一个 Rectangle 对象"<<endl;
    }
    ~Rectangle() {
        cout<<"回收了一个 Rectangle 对象"<<endl;
    }
    float getArea() {
        return length * width;
    }
private: 
    float length;
    float width;
};

class Circle : public Shape {
public: 
    Circle(float r) : radius(r) {
        cout<<"新建了一个 Circle 对象"<<endl;
    }
    ~Circle() {
        cout<<"回收了一个 Circle 对象"<<endl;
    }
    float getArea() {
        return PI * radius * radius;
    }
private: 
    float radius;
};

class Square : public Rectangle {
public: 
    Square(float n) : Rectangle(n, n) {
        cout<<"新建了一个 Square 对象"<<endl;
    }
    ~Square() {
        cout<<"回收了一个 Square 对象"<<endl;
    }
};

int main()
{
    Shape *sp; // 定义一个基类指针
    sp = new Rectangle(4, 6);
    cout<<"The area of the Rectange is: "<<sp->getArea()<<endl;
    delete sp;
    sp = new Circle(5);
    cout<<"The area of the Circle is: "<<sp->getArea()<<endl;
    delete sp;
    sp = new Square(5);
    cout<<"The area of the Square is: "<<sp->getArea()<<endl;
    delete sp;
    return 0;
}

// 虚函数 virtual 
// 指一个类中你希望重载的成员函数，当你用一个 基类指针或引用 指向一个继承类对象的时候，调用一个虚函数时, 实际调用的是继承类的版本。

// 本题输出
// 新建了一个 Shape 对象
// 新建了一个 Rectangle 对象
// The area of the Rectange is: 24
// 回收了一个 Rectangle 对象
// 回收了一个 Shape 对象
// 新建了一个 Shape 对象
// 新建了一个 Circle 对象
// The area of the Circle is: 78.5
// 回收了一个 Circle 对象
// 回收了一个 Shape 对象
// 新建了一个 Shape 对象
// 新建了一个 Rectangle 对象
// 新建了一个 Square 对象
// The area of the Square is: 25
// 回收了一个 Square 对象
// 回收了一个 Rectangle 对象
// 回收了一个 Shape 对象