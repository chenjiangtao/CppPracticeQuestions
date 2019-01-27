// 描述
// 编写程序定义类 Point，有数据成员 x，y，为其定义友元函数实现重载 + 。

#include<iostream>
using namespace std;

class Point {
public: 
    Point() : _x(0), _y(0) {}
    Point(int x, int y) : _x(x), _y(y) {}
    ~Point() {}
    void get();
    friend Point operator + (int _z, Point &_p);
    friend Point operator + (Point &_p, int _z);
private: 
    int _x, _y;
};

void Point :: get() {
    cout<<_x<<", "<<_y<<endl;
}

Point operator + (int _z, Point &_p) {
    return Point(_p._x + _z, _p._y + _z);
}

Point operator + (Point &_p, int _z) {
    return Point(_p._x + _z, _p._y + _z);
}

int main()
{
    Point a(2, 4);
    a.get(); // 2, 4
    a = a + 5;
    a.get(); // 7, 9
    a = 5 + a;
    a.get(); // 12, 14
    return 0;
}