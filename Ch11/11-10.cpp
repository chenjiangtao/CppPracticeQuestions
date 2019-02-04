// 描述
// 使用宽输入流从一个有中文字符的文本文件中读入所有字符，
// 统计每个字符出现的次数，将统计结果用宽输出流输出到另一个文本文件中。

#include <iostream> 
#include <fstream> 
#include <string>
#include <map> 
using namespace std;

int main()
{
    locale chinese("zh_CN.UTF-8"); // 设置中文字符
    wcin.imbue(chinese);
    wcout.imbue(chinese);

    wifstream infile("11-10-in.txt");
    wofstream outfile("11-10-out.txt");
    infile.imbue(chinese);
    outfile.imbue(chinese);

    map<wchar_t, int> str;

    wstring line;
    while (getline(infile, line)) {
        for (int i = 0; i < line.length(); i++) {
            str[line[i]]++;
        }
    }

    map<wchar_t, int>::iterator iter;
    for (iter = str.begin(); iter != str.end(); iter++) {
        outfile << iter->first << " " << iter->second << endl;
    }

    infile.close(); infile.clear();
    outfile.close(); outfile.clear();
    
    return 0;
}