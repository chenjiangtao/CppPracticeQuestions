#include <iostream>
using namespace std;

int maxl(int a, int b) {
    return a > b ? a : b;
}

int maxl(float a, int b) {
    return (int)a > b ? (int)a : b;
}

int maxl(int a, double b) {
    return a > (int)b ? a : (int)b;
}

int maxl(double a, double b) {
    return (int)a > (int)b ? (int)a : (int)b;
}

int main() {
    float a = 3.5;
    cout << maxl(3, 5) << endl;
    cout << maxl(a, 5) << endl; // --- 见下方注释
    cout << maxl(3, 5.5) << endl;
    cout << maxl(3.5, 5.5) << endl;
    return 0;
}

// 输入整数常量 eg. 3, 默认是 int 类型
// 输入浮点常量 eg. 3.5, 默认是 double 类型, 自动向下转换, 因此转成 int 和 float 都可以, 就会造成二义