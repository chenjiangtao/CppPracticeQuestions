//��������
//����������a,b������1=<a,b <=10000
//
//�������
//a��b�����Լ��
//
//��������
//1000 1000
//�������
//1000

#include <iostream>
using namespace std;
class Integer {
private:
    int _num;
public:
//���캯��
    Integer(int num) {
    	_num = num;
    }
//���㵱ǰInteger �� b֮������Լ��
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

