// 描述
// 例 9-13 的 bubbleSort 函数模板可以为数组排序，但如果将一个指针数组传递给它，在排序时将比较指针所存储地址的大小。
// 请利用函数模板重载技术，使得对指针数组进行排序时，以指针所指向内容为比较依据。

#include <iostream>
using namespace std;

template<typename T> 
bool largerthan(T m, T n) {
    return m > n;
}

template<typename T> 
bool largerthan(T *m, T *n) {
    return *m > *n;
}

template<typename T>
void bubbleSort(T a[], int n) {
    for (int pass = n - 1; pass >= 1; pass--) {
        int countSwap = 0;
        for (int i = 0; i < pass; i++) {
            if (largerthan(a[i], a[i + 1]) == 1) {
                swap(a[i], a[i + 1]);
                countSwap++;
            }
        }
        if (countSwap == 0) break;
    }
}

int main()
{
    int data[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int *p[10];

    for (int i = 0; i < 10; i++) {
        p[i] = &data[i];
    }
    bubbleSort<int *>(p, 10);
    cout << "指针数组排序结果：";
    for (int i = 0; i < 10; i++) {
        cout << *p[i] << " ";
    }

    cout << endl;
    return 0;
}

// 输出
// 指针数组排序结果：1 2 3 4 5 6 7 8 9 10 