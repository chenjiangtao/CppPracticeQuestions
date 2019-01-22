// 要求
// 用穷举法找出1-100间的质数，显示出来，用do-while语句实现。
// 标答是错的。do-while语句先循环后检验条件，因此在i = 2的情况下判断错误。
// 以下代码提供一种仍然只使用do-while语句的修正方案。

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 2, flag = 0;
    do {
        int j = 2;
        if (flag == 0) {
            cout<<i<<"是质数"<<endl;
        }
        i++;
        flag = 0;
        do {
            if (i % j == 0) {
                flag++;
            }
            j++;
        } while (j <= sqrt(i));
    } while (i <= 100);
    return 0;
}