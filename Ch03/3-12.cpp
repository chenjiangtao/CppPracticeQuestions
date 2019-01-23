// 描述
// 在主程序中提示输入整数 n ，编写函数用递归的方法求 1+2+……+n 的值。

# include<iostream>
using namespace std;

int sum(int _n)
{
    if(_n == 1) {
        return _n;
    }
    else {
        return _n + sum(_n - 1);
    }
}

int main()
{
    int n;
    cout<<"请输入一个正整数："<<endl;
    cin>>n;
    cout<<"从1累加到"<<n<<"的和是："<<sum(n)<<endl;
    return 0;
}