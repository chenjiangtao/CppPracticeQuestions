// 题目描述
// 实现一个学生类，包含学号（id），姓名（name），年级（grade）数据成员。为了输入输出的方便，需要对这个学生类重载“>>”和“<<”运算符，同时为了对多个学生按照学号从小到大排序，还需要重载“<”运算符，以使用STL里的sort函数。类的声明与主函数的测试代码已给出，请将类的实现与相关重载补充完整，使得程序正确运行并输出正确结果。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
class Student
{
public:
       int id;
       string name, grade;
       Student(){};
       Student(int id, string name, string grade): id(id), name(name), grade(grade) {}
       bool operator < (const Student & s) const {
           return id < s.id;
       }
};
 
istream & operator >> (istream & in, Student & s) {
    return cin >> s.id >> s.name >> s.grade;
}
ostream & operator << (ostream & out, Student & s) {
    return cout << s.id << " " <<s.name << " " << s.grade << endl;
}
 
/*请在这里填充代码*/
 
int main()
{
       vector<Student> sv;
       Student temp;
       while (cin >> temp)
       {
              sv.push_back(temp);
       }
       sort(sv.begin(), sv.end());
       for (int i = 0; i < sv.size(); ++i)
              cout << sv[i];
       return 0;
}