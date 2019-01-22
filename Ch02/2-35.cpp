// 要求
// 输出乘法九九算表

#include <iostream>
#include <iomanip>
using namespace std;

// /*undefined*/ setw (int n);
// Set field width
// Sets the field width to be used on output operations.

int main()
{
    int i = 1, j = 1;
    cout<<' ';
    for (i = 1; i < 10; i++) {
        cout<<setw(4)<<i;
    }
    cout<<endl;
    for (i = 1; i < 10; i++) {
        cout<<i<<setw(4);
        for (j = 1; j < 10; j++) {
            cout<<setw(4)<< i * j;
        }
        cout<<endl;
    }
    return 0;
}