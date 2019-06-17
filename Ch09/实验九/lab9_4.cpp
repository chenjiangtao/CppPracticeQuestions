#include "array1.h"

int main()
{
    Array arr;
    int last = 1,d = 1,M = 100003;
    for (int i = 0; i < 10; i ++)
    {
        int x = (last + i * d) % M;
        arr.add(x);
        last =  x; d = d * 3;
    }
    arr.insertSort();
    arr.selectSort();
    arr.BubbleSort();
    int ans = arr.seqSearch(1);
    cout << ans<< endl;
    return 0;
}