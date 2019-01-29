// 描述
// 编写程序提示用户输入一个班级中的学生人数 n，再一次提示用户输入 n 个人在课程 A 中的考试成绩
// 然后计算出平均成绩，显示出来。
// 请使用第 9 章中的数组类模板 Array 定义浮点型数组存储考试成绩

#include <cassert>

#ifndef _Array_H 
#define _Array_H

template <typename T> 
class Array {
public: 
    Array(int n);
    Array(const Array<T> &a); // 如果构造函数里需要申请内存，需要手动写复制构造函数
    ~Array();
    Array<T> & operator = (const Array<T> &a); // 重载 = 运算符，实现对象之间的整体赋值
    T & operator [] (int i); // 重载 [] 运算符
    operator T * (); // 重载 * 运算符
private: 
    T *list; // 用于存放动态分配的数组内存首地址
    int size; 
};

template <typename T> 
Array<T> :: Array(int n) {
    assert(n >= 0);
    size = n;
    list = new T [size]; // 动态分配 size 个 T 类型空间
}

template <typename T> 
Array<T> :: Array(const Array<T> &a) {
    size = a.size;
    list = new T [size];
    for (int i = 0; i < size; i++) {
        list[i] = a.list[i];
    }
}

template <typename T> 
Array<T> :: ~Array() {
    delete [] list;
}

template <typename T> 
Array<T> & Array<T> :: operator = (const Array<T> &a) {
    if(size != a.size) {
        delete [] list;
        list = new T [a.size];
    }
    for(int i = 0; i < size; i++) {
        list[i] = a.list[i];
    }
    return *this;
}

template <typename T>
T & Array<T> :: operator [] (int i) {
    assert(i >= 0 && i < size);
    return list[i];
}

template <typename T>
Array<T> :: operator T * () {
    return list;
}

#endif // Array_H

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int numOfStudents;
    double sum = 0;
    cout<<"请输入学生人数：";
    cin>>numOfStudents;
    Array<float> score(numOfStudents);
    for(int i = 0; i < numOfStudents; i++) {
        cout<<"请输入第"<<i + 1<<"个学生的成绩：";
        cin>>score[i];
        sum += score[i];
    }
    cout<<"平均成绩为："<<setprecision(4)<<sum / numOfStudents<<endl;
    return 0;
}

// 样例
// 请输入学生人数：3
// 请输入第1个学生的成绩：80
// 请输入第2个学生的成绩：80
// 请输入第3个学生的成绩：81
// 平均成绩为：80.33