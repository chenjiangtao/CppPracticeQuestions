// 描述
// 设计一个类模板 template<unsigned M, unsigned N> Permutation，内含一个枚举值 VALUE，Permutation<M, N>::VALUE 的值为排列数P(M, N)。

#include <iostream>
using namespace std;

template<unsigned M, unsigned N> 
class Permutation {
public: 
    enum {VALUE = Permutation<M, N - 1>::VALUE * (M - N + 1)};
};

template<unsigned M>
class Permutation<M, 1> {
public: 
    enum {VALUE = M};
};

int main()
{
    cout << Permutation<10, 2>::VALUE << endl;
    return 0;
}

// 输出
// 90