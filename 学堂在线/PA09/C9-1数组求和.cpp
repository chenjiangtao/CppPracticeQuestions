// 题目描述
// 编写一个模板函数getSum，接收一个数组，返回该数组所有元素的和。部分代码已给出，请将代码填补完整。

// 输入描述
// 每个测例共 3 行，第一行为两个整数 n,m(n > 1, m > 1) ，第二行为 n 个整数，用空格隔开，第三行为 m 个实数，用空格隔开。

// 输出描述
// 对每个测例输出两行，第一行为输入的n个整数的和，第二行为输入的m个实数的和。

#include <iostream>
using namespace std;
 
/*请在这里填充代码*/
template<typename T>
T getSum(const T *arr, int n) {
    T sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}
 
int main()
{
       int n, m;
       cin >> n >> m;
       int* arr_int = new int[n];
       double* arr_double = new double[m];
       for (int i = 0; i < n; ++i)
              cin >> arr_int[i];
       for (int i = 0; i < m; ++i)
              cin >> arr_double[i];
       cout << getSum(arr_int, n) << endl;
       cout << getSum(arr_double, m) << endl;
       return 0;
}
