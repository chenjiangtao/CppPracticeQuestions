// 描述
// 定义一个 Dog 类，包含体重和年龄两个成员变量及相应的成员函数。
// 声明一个实例 dog1，体重为 5，年龄为 10，使用 I/O 流把 dog1 的状态写入磁盘文件。
// 再声明另一个实例 dog2，通过读文件把 dog1 的状态赋给 dog2。
// 分别使用文本方式和二进制方式操作文件，看看结果有何不同，再看看磁盘文件的 ASCII 码有何不同。

#include <iostream> 
#include <fstream> 
using namespace std; 

class Dog {
public: 
    Dog(int w, int a):weight(w), age(a) {}
    ~Dog() {}
    void setWeight(int w);
    void setAge(int a);
    int getWeight();
    int getAge();
    void print();
private: 
    int weight;
    int age;
};

void Dog::setWeight(int w) {
    weight = w;
}

void Dog::setAge(int a) {
    age = a;
}

int Dog::getWeight() {
    return weight;
}

int Dog::getAge() {
    return age;
}

void Dog::print() {
    cout << "weight = " << weight <<endl;
    cout << "age = " << age << endl;
}

int main() 
{
    Dog dog1(5, 10);

    ofstream outfile("11-6.txt");
    outfile.write((char*)&dog1, sizeof(dog1));
    outfile.close();

    Dog dog2(0, 0);
    
    ifstream infile("11-6.txt");
    infile.read((char*)&dog2, sizeof(dog2));
    infile.close();
    
    cout << "dog2: " << endl;
    dog2.print();

    return 0;
}

// 输出
// dog2: 
// weight = 5
// age = 10