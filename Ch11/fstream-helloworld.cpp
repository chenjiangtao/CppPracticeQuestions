// 描述
// 使用 I/O 流以文本方式建立一个文件 test1.txt，写入字符“已成功写入文件！”。
// 用其他字处理程序打开，看是否正确写入。

#include <iostream> 
#include <fstream> 
using namespace std; 

int main()
{
    ofstream file1("test1.txt");
    file1 << "Hello World!";
    file1.close();

// test1.txt
// Hello World!

// 描述
// 使用 I/O 流以文本方式打开 test1.txt，读出其内容并显示出来。

    char ch;
    ifstream file2("test1.txt");
    while (file2.get(ch)) {
        cout << ch;
    }
    file2.close();

// 输出
// Hello World!

// 描述
// 使用 I/O 流以文本方式打开 test1.txt，在此文件后面添加字符“已成功添加字符！”，然后读出整个文件的内容显示出来。

    ofstream file3("test1.txt", ios::app);
    file3 << "已成功添加字符！";
    file3.close();

    ifstream file4("test1.txt");
    while (file4.get(ch)) {
        cout << ch;
    }
    file4.close();
    return 0;
}

// 输出
// Hello World!已成功添加字符！