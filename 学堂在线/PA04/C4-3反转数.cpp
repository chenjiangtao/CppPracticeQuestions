//输入描述
//一个正整数a ，且1=<a<=1,000,000,000
//
//输出描述
//a的反转形式
//
//样例输入
//1011
//样例输出
//1101

#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
//getLength()函数获取_num长度
    int getLength(){
    	if (_num == 0) return 0;
    	int l = 0, tmp = _num;
    	while (tmp) {
    		l++;
    		tmp /= 10;
		}
		return l;
    }
public:
//Integer类构造函数
    Integer(int num){
    	_num = num;
    }
//反转_num
    int inversed(){
    	long long inver = 0, tmp = _num;
    	while (tmp) {
    		inver += tmp % 10;
    		inver *= 10;
    		tmp /= 10;
		}
		return inver / 10;
    }
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
}
