// 题目描述
// 给定一个串a和串b，求b在a中出现次数

// 输入描述
// 字符串a,b的长度1<= len(a)<=100, 1<=len(b)<=len(a)

// 输出描述
// 一个数字

#include <iostream> 
#include <string> 

using namespace std;

bool check (string x, string y) {
    int m = x.length();
    int n = y.length();
    if (m < n) return false;
    for (int i = 0; i < n; ++i) {
        if (x[i] != y[i]) return false;
    }
    return true;
}

int main() {
    string a, b;
    cin >> a >> b;
    int count = 0;
    int m = a.length();
    int n = b.length();
    while (m >= n) {
        if (check(a, b)) count++;
        a = a.substr(1, m - 1);
        m--;
    }
    cout << count;
}