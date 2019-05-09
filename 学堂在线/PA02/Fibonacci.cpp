// 题目描述
// Fibonacci数列指满足如下通式的数列:

// F(0) = 0

// F(1) = 1

// F(n) = F(n-1) + F(n-2), n >= 2

// 求数列第n项.




// 输入描述
// 输入一个非负整数n.


// 输出描述
// 输出Fibonacci数列第n项的值, 测试样例不会超出int范围.


// 样例输入
// 3

// 样例输出
// 2

#include <iostream> 
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
        a += b;
        b = a;
    }
    return a;
}