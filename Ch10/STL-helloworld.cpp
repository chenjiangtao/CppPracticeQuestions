#include <iostream> 
#include <vector> // 动态数组(可变数组)
#include <algorithm> 
using namespace std;

void printVector(int v) {
    cout << v <<" ";
}

// STL 基本语法
void test01() {
    vector<int> v; // 定义一个容器，并制定容器存放的元素类型
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 通过STL提供的for_each算法进行遍历
    // 容器提供的迭代器

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end(); // 拿到两个迭代器

    // 容器中可能存放基础的数据类型，也可能存放自定义的数据类型
    for_each(pBegin, pEnd, printVector);
}

// 容器也可以存放自定义数据类型
class Person {
public: 
    Person(int age, int id):age(age),id(id){}
public: 
    int age;
    int id;
};

void test02() {
    vector<Person> v;
    Person p1(10, 20), p2(20,30), p3(50, 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it).age << " " << (*it).id << endl;
    }
}

int main()
{
    cout << "test01: " << endl;
    test01();
    cout << endl;
    cout << "test 02: " << endl;
    test02();
    return 0;
}

// 输出
// test01: 
// 10 20 30 40 
// test 02: 
// 10 20
// 20 30
// 50 60