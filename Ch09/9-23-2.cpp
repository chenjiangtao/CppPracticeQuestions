// 描述
// 设计一个类模板 template<unsigned M, unsigned N>Ged，内含一个枚举值 VALUE，Ged<M, N>::VALUE 的值为 M 和 N 的最大公约数。
// 提示：求最大公约数可以用辗转相除法，即：
// ged(m, n) = m ( m 能整除 n) 或 ged(n%m, m) ( m 不能整除 n)。

#include <iostream> 
using namespace std;

template<unsigned M, unsigned N> 
class Ged {
public: 
    enum {VALUE = (N % M == 0) ? M : Ged<N % M, M>::VALUE};
};

template<unsigned N>
class Ged<0, N> {
public: 
    enum {VALUE = -1};
};

int main()
{
    cout << Ged<12, 18>::VALUE << endl;
    return 0;
}

// 输出
// 6