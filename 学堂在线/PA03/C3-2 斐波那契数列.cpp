//题目描述
//斐波那契数列f(n)满足以下定义：
//
//f(0) = 1, f(1) = 1, f(n) = f(n-1) + f(n-2) (n >= 2)。
//
//请用递归的方法编写函数，对于给定的n，求出斐波那契数列的第n项f(n)
//
//
//输入描述
//每行输入一个整数 n
//
//0 <= n<= 30
//
//
//输出描述
//对于每一行输入，输出斐波那契数列第n项的值f(n)
//
//
//样例输入
//1
//10
//25
//样例输出
//1
//89
//121393 

#include <iostream>
using namespace std;

long long computeFib(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	return computeFib(n - 1) + computeFib(n - 2);
}

int main() {
	int n;
	while (cin >> n) {
		cout << computeFib(n) << endl;
	}
	system("pause");
	return 0;
}
