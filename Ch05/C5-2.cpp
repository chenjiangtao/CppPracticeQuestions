// 题目描述
// 请实现一个老鼠类，下面已给出代码模板，请根据main函数中对该类的操作，补充类实现部分完成代码。

// 该类有个公有静态变量num记录该类的所有对象数，主函数将会在不同语句之后输出对象数，只有正确地实现该类，保证num正确记录该类的对象数，才能输出正确的结果。

#include <iostream>
using namespace std;
  
class Mouse{
public: 
    static int num;
    Mouse() {
        num++;
    }
    Mouse(const Mouse &x) {
        num++;
    }
    ~Mouse() {
        num--;
    }
};
  
void fn(Mouse m);
int Mouse::num = 0;  
int main()
{
    
    Mouse a;
    cout << Mouse::num << endl; 
    Mouse b(a);
    cout << Mouse::num << endl; 
    for (int i = 0; i < 10; ++i)
    {
        Mouse x;
        cout << Mouse::num << endl; 
    }
    fn(a);
    cout << Mouse::num << endl; 
    return 0;
}
  
void fn(Mouse m)
{
    cout << Mouse::num << endl; 
    Mouse n(m);
    cout << Mouse::num << endl; 
}  