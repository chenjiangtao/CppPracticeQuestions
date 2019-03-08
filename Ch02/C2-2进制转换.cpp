// 题目描述
// 已知一个只包含 0 和 1 的二进制数，长度不大于 10 ，将其转换为十进制并输出。

// 输入描述
// 输入一个二进制整数n，其长度不大于10

// 输出描述
// 输出转换后的十进制数， 占一行

// 样例输入
// 110

// 样例输出
// 6

#include <iostream>
using namespace std;

int main() {
	long int bin;
	cin >> bin;
	int dec = 0, p = 1;
	while (bin) {
		int temp = bin % 10;
		dec += temp * p;
		p *= 2;
		bin /= 10;
	}
	cout << dec;
	return 0;
}