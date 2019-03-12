#include <iostream>
using namespace std;

struct Time {
    short year;
    short month;
    short day;
    short hour;
    short minute;
    short sec;
};

int main() {
    struct Time t;
    cout << "请输入年：";
    cin >> t.year;
    cout << "请输入月：";
    cin >> t.month;
    cout << "请输入日：";
    cin >> t.day;
    cout << "请输入时：";
    cin >> t.hour;
    cout << "请输入分：";
    cin >> t.minute;
    cout << "请输入秒：";
    cin >> t.sec;
    cout << "时间为：" << t.year << "年" << t.month << "月" << t.day << "日" << t.hour << "时" << t.minute << "分" << t.sec << "秒" << endl;
    return 0;

}