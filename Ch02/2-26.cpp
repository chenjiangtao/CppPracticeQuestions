#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char flag;
    while (1) {
        cout<<"现在正在下雨吗？"<<endl;
        cin>>flag;
        if (toupper(flag) == 'Y') {
            cout<<"现在正在下雨。"<<endl;
            break;
        }
        else if (toupper(flag) == 'N') {
            cout<<"现在没有下雨。"<<endl;
        }
    }
    return 0;
}