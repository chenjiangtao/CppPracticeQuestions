#include <iostream> 
#include <ctime>
#include <iomanip>
using namespace std;

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
        int num = 5;
        int i = 0;
        float next = num;
        int num4old = 0;

        clock_t start,finish;
        start = clock();

        while (i < n) {
            next = (next - 1) * 4 / 5;
            num4old++;
            i++;
            if (next != (int)next) {
                i = 0;
                num++;
                next = num;
                num4old = 0;
            }
        }
        num4old += next;
        finish = clock();

        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout << "最后一只猴子留给老猴子 " << (int)next << " 个桃子" << endl;
		cout << "原先至少有 " << num <<" 个桃子"<< endl;
		cout << "老猴子至少分到 "<< num4old <<" 个桃子"<< endl;
        cout << "算法所需时间为：" << (double)(finish - start) / CLOCKS_PER_SECOND << "s" << endl;
        cout << endl;
    }
    return 0;
}