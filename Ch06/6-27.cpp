// 描述 
// 定义一个 Employee 类，其中包括表示姓名、地址、城市和邮编等属性，包括 setName() 和 display() 等函数。
// display() 使用 cout 语句显示姓名、地址、城市和邮编等属性，函数 setName() 改变对象的姓名属性。
// 实现并测试这个类。

#include <iostream>
#include <string>
using namespace  std;

class Employee {
public: 
    Employee(char const *n, char const *ad, char const *c, char const *code) {
        strcpy(name, n);
        strcpy(address, ad);
        strcpy(city, c);
        strcpy(zip, code);
    }
    ~Employee() {}
    void setName(char const *newname);
    void display();
private: 
    char name[100];
    char address[100];
    char city[20];
    char zip[20];
};

void Employee :: setName(char const *newname) {
    strcpy(name, newname);
}

void Employee :: display() {
    cout<<"姓名："<<name<<endl;
    cout<<"地址："<<address<<endl;
    cout<<"城市："<<city<<endl;
    cout<<"邮编："<<zip<<endl;
}

int main()
{
    Employee e("张三", "平安大街 3 号", "北京", "100000");
    e.display();
    e.setName("李四");
    cout<<endl;
    e.display();
    return 0;
}

// 输出：
// 姓名：张三
// 地址：平安大街 3 号
// 城市：北京
// 邮编：100000

// 姓名：李四
// 地址：平安大街 3 号
// 城市：北京
// 邮编：100000