// 题目描述
// 打印 n 阶实心菱形

// 输入描述
// 输入一个整数n，n<=10

// 输出描述
// 输出 n 阶实心菱形 ， 占 2*n-1 行

// 样例输入
// 3
// 样例输出
//   *
//  ***
// *****
//  ***
//   *

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) 
			cout << " ";
		for (int j = 0; j < 2 * (n - i) - 1; j++) 
			cout << "*";
		for (int j = 0; j < i; j++) 
			cout << " ";
		cout << endl;
	} 
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < i; j++) 
			cout << " ";
		for (int j = 0; j < 2 * (n - i) - 1; j++)
			cout << "*";
		for (int j = 0; j < i; j++)
			cout << " ";
		cout << endl;
	}
	return 0;
}