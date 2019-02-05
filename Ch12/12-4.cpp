// 描述
// 设计一个异常抽象类 Exception，在此基础上派生一个 OutOfMemory 类相应内存不足，一个 RangeError 类相应输入的数不再指定范围内。
// 实现并测试这几个类。

#include <iostream>
using namespace std;

class Exception {
public: 
    Exception() {}
    virtual ~Exception() {}
    virtual void printError() {}
};

class OutOfMemory : public Exception {
public: 
    OutOfMemory() {}
    ~OutOfMemory() {}
    virtual void printError() {
        cout << "Out Of Memory!" << endl;
    }
};

class RangeError : public Exception {
public: 
    RangeError(unsigned val):val(val) {}
    ~RangeError() {}
    virtual void printError() {
        cout << "Input " << val << " is out of range!" << endl;
    }
    unsigned val;
};

void inputInteger() {
    int *arr;
    int val;
    while (val != -1) {
        arr = new int [1];
        if (!arr) {
            throw OutOfMemory();
        }
        cout << "Please enter an integer (0, 999): ";
        cin >> val;
        if (val > 999 || val == 0) {
            throw RangeError(val);
        }
    }
}

int main()
{
    try {
        inputInteger();
    } catch(Exception &theException) {
        theException.printError();
    } 
    return 0;
}