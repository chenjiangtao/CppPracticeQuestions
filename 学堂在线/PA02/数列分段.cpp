// 题目描述
// 给定一个整数数列, 数列中连续相同的最长整数序列算成一段, 问数列中共有多少段?


// 输入描述
// 输入的第一行包含一个整数n, 1 <= n <= 1000, 表示数列中整数的个数.

// 第二行包含n个整数a1, a2, ..., an表示给定的数列, 0 <= ai <= 1000, 相邻的整数之间用一个空格分隔.


// 输出描述
// 输出一个整数, 表示给定的数列有多个段.


// 样例输入
// 8
// 8 8 8 0 12 12 8 0

// 样例输出
// 5

#include <iostream> 
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 1;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[j - 1])
            count++;
    }
    cout << count << endl;
    return 0;
}