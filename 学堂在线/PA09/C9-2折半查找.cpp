// 题目描述
// 编写一个折半查找的模板函数binSearch()，接收一个数组，数组长度和要查找的元素key，按查找顺序输出查找过程中访问的所有元素下标。部分代码已给出，请将代码填补完整。

#include <iostream>
using namespace std;
 
template <class T>
int binSearch(T arr[], int n, T key) {
    int left = 0, right = n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        cout << mid << endl;
        if (arr[mid] < key) 
            left = mid + 1;
        else if (arr[mid] > key) 
            right = mid - 1;
        else return mid;
    }
    return -1;
}
 
int main()
{
       int n, m;
       int key1;
       double key2;
       cin >> n >> m >> key1 >> key2;
       int* arr_int = new int[n];
       double* arr_double = new double[m];
       for (int i = 0; i < n; ++i)
              cin >> arr_int[i];
       for (int i = 0; i < m; ++i)
              cin >> arr_double[i];
       binSearch(arr_int, n, key1);
       binSearch(arr_double, m, key2);
       return 0;
}