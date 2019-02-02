// 描述
// 编写一个程序，从键盘输入一个个单词，每接收到一个单词后，输出该单词是否曾经出现过以及出现的次数。
// 可以尝试分别用多重集合（multiset）和映射（map）两种途径实现。
// 10-8-1 将通过 multiset 实现。

#include <iostream> 
#include <string>
#include <set> 
using namespace std;

int main() {
    multiset<string> base;
    while (1) {
        string str;
        cout << "Please input string: ";
        cin >> str;
        if (str == "QUIT") {
            break;
        }
        int counter = base.count(str);
        if (counter > 0) {
            cout << "This word has been input with " << counter << " times " << endl;
        }
        else {
            cout << "This word has not been input." << endl;
        }
        base.insert(str);
    }
    return 0;
}

// 样例
// Please input string: apple
// This word has not been input.
// Please input string: apple
// This word has been input with 1 times 
// Please input string: apple
// This word has been input with 2 times 
// Please input string: apple
// This word has been input with 3 times 
// Please input string: apple
// This word has been input with 4 times 
// Please input string: QUIT