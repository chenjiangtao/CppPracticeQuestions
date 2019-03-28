//输入描述
//两个正整数a,b，并且1=<a,b <=10000
//
//输出描述
//a和b的最大公约数
//
//样例输入
//1000 1000
//样例输出
//1000

#include <iostream>
using namespace std;
class Integer {
private:
    int _num;
public:
//构造函数
    Integer(int num) {
    	_num = num;
    }
//计算当前Integer 和 b之间的最大公约数
    int gcd(Integer b) {
    	int ans = min(_num, b._num);
    	for (ans = min(_num, b._num); ans >= 1; ans--) {
    		if (_num % ans == 0 && b._num % ans == 0) break;
		}
		return ans;
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}

