// 题目描述
// 编写一个程序，输入一个浮点数和输出格式要求，按照格式要求将该浮点数输出。给定非负整数m和n，表示输出的浮点数小数点前的宽度为m，若宽度不够则在前面补0，小数点后的宽度为n，若宽度不够则在后面补0(补充说明：当n=0时，只需输出整数部分，当m,n都为0时，则输出0)。

// 输入描述
// 每个测例共 2 行，第一行为两个整数 m,n(n >= 0, m >= 0) ，第二行为一个浮点数。

// 输出描述
// 对每个测例输出的浮点数占一行，其小数点前宽度为m，小数点后宽度为n，不足时补零。

#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
using namespace std;
int n,m;
double a;
int main(void)
{
	while(cin >> m >> n >> a)
	{
		if(m==0 && n==0)
			cout << 0 << endl;
		else
		{
			cout << setw(m) << setfill('0') << int(a);
			if(n!=0)
			{
				ostringstream os;//从字符串中输出
				os << setiosflags(ios_base::fixed);//左对齐
				os << fixed << setprecision(n+1) << a-int(a);
				//这里的n+1是为了避免四舍五入带来的问题，因为样例明显不是四舍五入规则的
				os << setiosflags(ios_base::fixed);
				string str=os.str();
				for(int i=1;i<=n+1;i++)
					cout << str[i];
			}        
			cout << endl;   
		}   
	}
	return 0;    
}