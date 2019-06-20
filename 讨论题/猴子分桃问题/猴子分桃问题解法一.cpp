#include <iostream> 
#include <ctime>
#include <iomanip>
using namespace std;

const double CLOCKS_PER_SECOND = ((clock_t)1000000);

int main() {
    while (true) {
        cout << "请输入小猴子的数量n (n <= 13)：";
        int n;
        cin >> n;
        if (n < 1) exit(0);
		if (n > 13) {
			cout << "超出范围！" << endl;
			exit(0);
		}
        long long num = 5;
        long long next = num;
        long long num4old = 0;

        clock_t start,finish;
        start = clock();

        int i = 0;
        while (i < n) {
            if ((next - 1) % 5 == 0) {
                next = (next - 1) / 5 * 4;
                num4old++;
                i++;
            }
            else {
                i = 0;
                num++;
                next = num;
                num4old = 0;
            }
        }
        num4old += next;

        finish = clock();

        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout << "最后一只猴子留给老猴子 " << next << " 个桃子" << endl;
		cout << "原先至少有 " << num <<" 个桃子"<< endl;
		cout << "老猴子至少分到 "<< num4old <<" 个桃子"<< endl;
        cout << "算法所需时间为：" << (double)(finish - start) / CLOCKS_PER_SECOND << " 秒" << endl;
        cout << endl;
    }
    return 0;
}