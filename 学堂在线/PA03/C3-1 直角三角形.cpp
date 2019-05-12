//题目描述
//
//输入一个三角形的3边长度，判断该三角形是否为直角三角形，若是则输出True，若不是则输出False。推荐做法：定义一个函数，接受三个int参数，返回bool，再用主函数调用之。
//
//
//输入描述
//每行输入三个由空格隔开的整数 a, b, c ，表示三角形的 3 条边长
//
//1 <= a,b ,c <= 10000
//
//输出描述
//对于每一行输入，输出True或者False表明是否为直角三角形
//
//样例输入
//3 4 5
//
//样例输出
//True 
//样例输入
//6 7 8
//
//样例输出
//False

#include <iostream>
using namespace std;

bool isRight(long long a, long long b, long long c) {
	if (a <= 0 || b <= 0 || c <= 0) return false;
	if (a >= b && a >= c) {
		if (a * a == b * b + c * c) return true;
	}
	else if (b >= a && b >= c) {
		if (b * b == a * a + c * c) return true;
	}
	else {
		if ( c * c == a * a + b * b) return true;
	}
	return false;
} 

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (isRight(a, b, c)) cout << "True";
	else cout << "False";
	return 0;
}
