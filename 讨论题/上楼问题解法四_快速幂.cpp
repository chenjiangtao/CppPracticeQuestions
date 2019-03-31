#include <iostream>
using namespace std;

int a[4]={1,0,0,1};//这里的数组可以用四个变量代替，学了类之后可以用类代替 

//下面的函数本质是求(0,1,1,1)这个矩阵的n次幂，学了类之后可以进行简化。 
//此算法时间复杂度为O(log N)。但在本题的数据规模（a[3]<MAX_INT）下，速度优化不明显 
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


