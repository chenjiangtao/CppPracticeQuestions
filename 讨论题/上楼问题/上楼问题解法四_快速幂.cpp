#include <iostream>
using namespace std;

int a[4]={1,0,0,1};//���������������ĸ��������棬ѧ����֮������������ 

//����ĺ�����������(0,1,1,1)��������n���ݣ�ѧ����֮����Խ��м򻯡� 
//���㷨ʱ�临�Ӷ�ΪO(log N)�����ڱ�������ݹ�ģ��a[3]<MAX_INT���£��ٶ��Ż������� 
void power(int n) 
{
	int b[4]={0,1,1,1};
	int a0,a1,a2,a3,b0,b1,b2,b3;
    while (n)
	{
		b0=b[0];
		b1=b[1];
		b2=b[2];
		b3=b[3];
        if (n%2!=0)
        {
        	a0=a[0];
        	a1=a[1];
        	a2=a[2];
        	a3=a[3];
        	a[0]=a0*b0+a1*b2;
        	a[1]=a0*b1+a1*b3;
        	a[2]=a2*b0+a3*b2;
        	a[3]=a2*b1+a3*b3;        	
		}
        b[0]=b0*b0+b1*b2;
        b[1]=b0*b1+b1*b3;
        b[2]=b2*b0+b3*b2;
        b[3]=b2*b1+b3*b3;
        n=n/2;
    }
    return ;
}

int main()
{
	int n;
	cin>>n;
	power(n);
	cout<<a[3]<<endl;
	return 0;
}


