#include <iostream>
#include <ctime>
using namespace std;

/* ================================= 需要讲的部分 ======================================
* 本题分为算法分析和代码实现两部分
* ------------------------------------ 算法设计 ---------------------------------------
* 假设最初有 x0 个桃子
* 第一只猴子拿走 (x0-1)/5，因此还剩下 x1=(x0-1)*4/5 个桃子，老猴子得到 1 个桃子 
* 第二只猴子同理，拿走后剩下 x2=(x1-1)*4/5 个桃子，老猴子得到 1 个桃子 
* 以此类推…… 
* 最后一只猴子拿走 (x(n-1)-1)/5，拿走后剩下 xn=(x(n-1)-1)*4/5 个桃子
* 由此可得 x(n-1) = xn * 5/4 + 1  
* 这样就可以倒着推回去了
* 由于每一次计算的结果都必须是正整数，因此如果过程中出现了非整数，则返回最初的 xn，将其 +1，直到递归 n 次的结果均为整数为止
* ------------------------------------ 代码实现 ---------------------------------------
* 首先创建一个 loop，方便用户多次输入 n 值；
* 由于 xn 需要是正整数，因此 xn 最小值为 4，初始 x_n 为 4；
* 老猴子在最后一次得到 xn 个桃子，因此将 x_n 值赋给 num4old；
* 在 while 循环过程中，如果 num != (int)num，则说明 num 不是整数，将一切返回到最初，并将 x_n + 1 
* =================================================================================== */

const double CLOCKS_PER_SECOND = ((clock_t)1000);

int main() {
	while (true) {
		cout << "请输入小猴子的数量n (n <= 35)：";
		int n;
		cin >> n;
		if (n < 1) exit(0);
		if (n > 35) {
			cout << "超出范围！" << endl;
			exit(0);
		}
		int x_n = 1;
		int num4old = x_n;
		int i = 0;
		float num = x_n;

		clock_t start,finish;
        start = clock();

		while (i < n){
			num = (float)num * 5 / 4 + 1;
			num4old++;
			i++;
			if (num != (int)num) {
				i = 0;
				x_n++;
				num = x_n;
				num4old = x_n;
			}
		}
		
		finish = clock();

		cout.setf(ios_base::fixed,ios_base::floatfield);
		cout << "最后一只猴子留给老猴子 " << x_n << " 个桃子" << endl;
		cout << "原先至少有 " << (int)num <<" 个桃子"<< endl;
		cout << "老猴子至少分到 "<< num4old <<" 个桃子"<< endl;
		cout << "算法所需时间为：" << (double)(finish - start) / CLOCKS_PER_SECOND << "s" << endl;
		cout << endl;
	}
	return 0; 
} 
