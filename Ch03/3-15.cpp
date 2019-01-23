// 描述
// 编写递归函数 getPower 计算 x 的 y 次幂，在同一个程序中针对整型和实型实现两个重载的函数：
// int getPower(int x, int y); 当 y < 0 时返回0
// double getPower(double x, int y);

# include<iostream>
# include <iomanip>
using namespace std;

// cout<<setiosflags(ios::fixed)<<setprecision(4)<<a 保留4为小数
// 当没有 setiosflags(ios::fixed) 时，输出4位有效数字

int getPower(int _x, int _y)
{
    if(_y == 1) {
        return _x;
    }
    else if(_y <= 0) {
        return 0;
    }
    else {
        return _x * getPower(_x, _y - 1);
    }
}

double getPower(double _x, int _y)
{
    if(_y == 1) {
        return _x;
    }
    else if(_y <= 0) {
        return 0;
    }
    else {
        return _x * getPower(_x, _y - 1);
    }
}

int main()
{
    double x;
    int y;
    cin>>x;
    cin>>y;
    int x_ = (int)x;
    if(x - x_ == 0) {
        cout<<getPower(x_, y)<<endl;
    }
    else {
        cout<<setiosflags(ios::fixed)<<setprecision(4)<<getPower(x, y)<<endl;
    }
    return 0;
}