// 题目描述
// 栈的应用非常广泛。请先实现一个栈模板类（定义已在下面给出），然后利用这个栈类解决下面的问题：
// 给定一个字符串，长度小于1000，其中只包含左右括号和大小写英文字母。请编写程序判断输入的字符串里的左右括号是否全部是匹配的，匹配规则即从内到外左括号都与其右边距离最近的右括号匹配。如匹配，输出“Yes”,否则，输出“No”。

// 输入描述
// 每个测例输入一个字符串，长度小于 1000 ，大于 0 。

// 输出描述
// 若输入字符串内的所有括号正确匹配，输出“Yes”，否则输出“No”。

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
 
template<class T>
class Stack
{
private:
       T list[MAX + 1];
       int top;
public:
       Stack();
       void push(const T &item);//将item压栈
       T pop();//将栈顶元素弹出栈
       const T & peek() const;//访问栈顶元素
       bool isEmpty() const;//判断是否栈空
};
//请完成栈模板类的实现，并解决括号匹配问题

template<class T>
Stack<T>::Stack() {
    top = -1;
}

template<class T> 
void Stack<T>::push(const T &item) {
    top++;
    list[top] = item;
}

template<class T> 
T Stack<T>::pop() {
    top--;
    return list[top + 1];
}

template<class T> 
const T & Stack<T>::peek() const {
    return list[top];
}

template<class T> 
bool Stack<T>::isEmpty() const {
    return top == -1;
}

bool check(string str) {
    Stack<char> s;
    int l = str.length();
    for (int i = 0; i < l; ++i) {
        if (!s.isEmpty() && s.peek() == '(' && str[i] == ')')
            s.pop();
        else if (str[i] == '(' || str[i] == ')')
            s.push(str[i]);
    }
    return s.isEmpty();
}

int main() {
    string str;
    cin >> str;
    if (check(str)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}