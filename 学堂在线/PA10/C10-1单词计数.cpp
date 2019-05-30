// 题目描述
// 编写一个程序，从键盘输入一个个单词，每接收到一个单词后，输出该单词曾经出现过的次数，接收到“QUIT”单词后程序直接退出。

// 输入描述
// 一行一个单词，"QUIT"结束

// 输出描述
// 每行输出为相应单词统计结果

// 样例输入
// c++
// map
// set
// map
// vector
// set
// multiset
// c++
// QUIT

// 样例输出
// 0
// 0
// 0
// 1
// 0
// 1
// 0
// 1

#include <iostream>
#include <map> 
#include <string> 
#include <vector>
using namespace std;

int main() {
    string input; 
    map<string, int> m;
    m.clear();
    vector<int> v;
    v.clear();
    while (input != "QUIT") {
        cin >> input;
        v.push_back(m[input]);
        m[input]++;
    }
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != --v.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}