//��������
//һ��������a ����1=<a<=1,000,000,000
//
//�������
//a�ķ�ת��ʽ
//
//��������
//1011
//�������
//1101

#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
//getLength()������ȡ_num����
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
//Integer�๹�캯��
    Integer(int num){
    	_num = num;
    }
//��ת_num
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
