// 题目描述
// 任意给定 n 个整数，求这 n 个整数序列的和、最小值、最大值

// 输入描述
// 输入一个整数n，代表接下来输入整数个数，n<=100,接着输入n个整数，整数用int表示即可。

// 输出描述
// 输出整数序列的和、最小值、最大值。用空格隔开，占一行

// 样例输入
// 2
// 1 2
// 样例输出
// 3 1 2

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	cin >> a;
	int sum = a, min = a, max = a;
	int i = 1;
	while (i < n) {
		int b;
		cin >> b;
		sum += b;
		if (b < min) min = b;
		else if (b > max) max = b;
		i++;
	}
	cout << sum << " " << min << " " << max;
	return 0; 
}
