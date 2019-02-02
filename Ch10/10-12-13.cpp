// 描述
// 编写一个产生器，用来产生 0 到 9 范围内的随机数。
// 建立一个顺序容器，使用该产生器和 generator 算法为该容器的元素赋值。
// 编写一个二元函数对象，用来计算 x 的 y 次方，其中 x 和 y 都是整数。
// 利用该函数对象和 transform 算法，并结合适当的函数适配器，对于习题 10-12 所生成的整数序列中的每个元素 n，分别输出 5^n n^7 和 n^n。

#include <iostream>
#include <iterator> 
#include <cstdio>
#include <ctime>
#include <list>
using namespace std;

int myRandom() {
    return rand() % 10;
}

void printList(int _l) {
    cout << _l << " ";
}

int Power(int _m, int _n) { // m^n
    if(_n == 0) return 1;
    else {
        return _m * Power(_m, _n - 1);
    }
}

int Power1(int _n) {
    return Power(5, _n);
}

int Power2(int _m) {
    return Power(_m, 7);
}

int Power3(int _n) {
    return Power(_n, _n);
}

int main() {
    srand(time(0));
    list<int> l(20);
    generate(l.begin(), l.end(), myRandom); 
    cout << "the original list is: " << endl;
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int> l1, l2, l3;
    list<int> temp = l;

    transform(l.begin(), l.end(), l.begin(), Power1);
    l1 = l; l = temp;
    cout << "for eacn n in list, output 5^n: " << endl;
    for_each(l1.begin(), l1.end(), printList);
    cout << endl;

    transform(l.begin(), l.end(), l.begin(), Power2);
    l2 = l; l = temp;
    cout << "for each n in list, output n^7: " << endl;
    for_each(l2.begin(), l2.end(), printList);
    cout << endl;

    transform(l.begin(), l.end(), l.begin(), Power3);
    l3 = l; l = temp;
    cout << "for each n in list, output n^n: " << endl;
    for_each(l3.begin(), l3.end(), printList);
    cout << endl;

    return 0;
}

// 样例输出
// the original list is: 
// 9 3 9 1 0 3 9 6 1 7 2 7 0 3 6 7 4 4 4 0 
// for eacn n in list, output 5^n: 
// 1953125 125 1953125 5 1 125 1953125 15625 5 78125 25 78125 1 125 15625 78125 625 625 625 1 
// for each n in list, output n^7: 
// 4782969 2187 4782969 1 0 2187 4782969 279936 1 823543 128 823543 0 2187 279936 823543 16384 16384 16384 0 
// for each n in list, output n^n: 
// 387420489 27 387420489 1 1 27 387420489 46656 1 823543 4 823543 1 27 46656 823543 256 256 256 1 