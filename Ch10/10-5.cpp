// 描述
// 约瑟夫问题：n 个骑士编号 1， 2， ……n，围坐在圆桌旁，编号为 1 的骑士从 1 开始报数，报到 m 的骑士出列，然后从下一个位置开始再从 1 开始报数，找出最后留在圆桌旁的骑士的编号。
// (1) 编写一个函数模板，以一种顺序容器的类型作为模板参数，在模板中使用指定类型的顺序容器求解约瑟夫问题，m、n 是该函数模板的形参。
// (2)分别以 vector<int> deque<int> list<int> 作为类型参数调用该函数模板，调用时将 m 设为较大的数，n 设为较小的数，观察三种情况下调用该函数模板所需花费的时间。

#include <iostream> 
#include <typeinfo>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
using namespace std;

template<typename T>
void joseph(T a, int m, int n) {
    for (int i = 1; i <= m; i++) {
        a.push_back(i);
    }
    int counter = 0;
    int outter = 0;
    typename T::iterator ans;

    clock_t start = clock(), finish;

    while(outter < m) {
        for (typename T::iterator iter = a.begin(); iter != a.end(); iter++) {
            if (*iter != 0) {
                if (outter < m - 1) {
                    counter++;
                    if (counter == n) {
                        *iter = 0;
                        outter++;
                        counter = 0;
                    }
                }
                else {
                    ans = iter;
                    outter++;
                }
            }
        }
    }

    finish = clock();

    cout << "The answer to the Joseph question with m = " << m << " and n = " << n << " is: " << *ans << endl;
    cout << "Time consumed with " << typeid(a).name() << " is: " << 1.0 * (finish - start) / CLOCKS_PER_SEC << "s" << endl;
}

int main() {
    vector<int> v;
    deque<int> d;
    list<int> l;
    joseph(v, 100000, 5);
    joseph(d, 100000, 5);
    joseph(l, 100000, 5);
    return 0;
}

// 输出
// The answer to the Joseph question with m = 100000 and n = 5 is: 40333
// Time consumed with NSt3__16vectorIiNS_9allocatorIiEEEE is: 0.059447s
// The answer to the Joseph question with m = 100000 and n = 5 is: 40333
// Time consumed with NSt3__15dequeIiNS_9allocatorIiEEEE is: 0.134609s
// The answer to the Joseph question with m = 100000 and n = 5 is: 40333
// Time consumed with NSt3__14listIiNS_9allocatorIiEEEE is: 0.066239s