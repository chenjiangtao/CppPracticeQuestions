// 要求
// 声明枚举类型 Weekday，包括 SUNDAY 到 SATURDAY 7个元素
// 在程序中声明 Weekday 类型的变量，对其赋值，声明整型变量，看看能否对其赋 Weekday 类型的值。

#include<iostream>
using namespace std;

int main()
{
    enum Weekday {
        SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
    };
    Weekday i;
    i = MONDAY;
    int j;
    j = 4; 
    j = i;
    cout<<i<<endl; // 输出1
    cout<<j<<endl; // 输出1
    return 0;
}