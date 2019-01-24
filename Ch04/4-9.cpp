// 描述
// 设计并测试一个名为 Rectangle 的矩形类，其属性为矩形的左下角与右上角两个点的坐标，根据坐标能计算矩形的面积

#include <iostream>
using namespace std;

class Rectangle {
public: 
    void setLeft_bottom(int l, int b) {
        left = l;
        bottom = b;
    }
    void setRight_top(int r, int t) {
        right = r;
        top = t;
    }
    int getArea() {
        return (right - left) * (top - bottom);
    }
private: 
    int left;
    int bottom;
    int right;
    int top;
};

int main()
{
    Rectangle rect;
    rect.setLeft_bottom(50, 20);
    rect.setRight_top(100, 80);
    cout<<"The area is: "<<rect.getArea()<<endl;
    return 0;
}