//题目描述
//斐波那契数列f(n)满足以下定义：
//
//f(0) = 1, f(1) = 1, f(n) = f(n-1) + f(n-2) (n >= 2)。
//
//本题的数据规模比原先更大
//
//
//输入描述
//每行输入一个整数 n
//
//0 <= n<= 80
//
//
//输出描述
//对于每一行输入，输出斐波那契数列第n项的值f(n)

#include <iostream>
using namespace std;

long long computeFib(int n) {
	// if (n == 0) return 1;
	long long a = 0, b = 1, temp;
	for (int i = 0; i < n+1; i++) {
		temp = b;
		b += a;
		a = temp;
	}
	return a;
}

int main() {
	int n;
	while (cin >> n) {
		cout << computeFib(n) << endl;
	}
	return 0;
}
