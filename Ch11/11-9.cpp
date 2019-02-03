// 描述
// 编写程序实现如下功能：
// 打开指定的一个文本文件，再每一行前加行号后将其输出到另一个文本文件中。

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile("11-9-in.txt");
    ofstream outfile("11-9-out.txt");

    string line;
    int num_line = 0;
    while (getline(infile, line)) {
        outfile << ++num_line << ". " << line << endl;
    }

    infile.close(); infile.clear();
    outfile.close(); outfile.clear();

    return 0;
}