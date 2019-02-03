// 描述
// 编写一个程序，从键盘输入两组整数（可以看做两个集合），分别输出它们的交集、并集和差集。
// 程序中需要用到 sort, set_intersection, set_union, set_difference 等算法。

#include <iostream> 
#include <set> 
using namespace std;

void getValue(int val) {
    cout << val << " ";
}

int main() {
    set<int> A;
    set<int> B;
    int A_i, B_i;

    cout << "请输入集合 A 的元素个数：";
    cin >> A_i;
    cout << "请输入集合 A 的 " << A_i << " 个元素：";
    while (A_i--) {
        int num;
        cin >> num;
        A.insert(num);
    }

    cout << "请输入集合 B 的元素个数：";
    cin >> B_i;
    cout << "请输入集合 B 的 " << B_i << " 个元素：";
    while (B_i--) {
        int num;
        cin >> num;
        B.insert(num);
    }

    cout << "排序后集合 A 为：";
    for_each(A.begin(), A.end(), getValue);
    cout << endl;

    cout << "排序后集合 B 为：";
    for_each(B.begin(), B.end(), getValue);
    cout << endl;

    set<int> AinterB, AunionB, AdiffB, BdiffA;

    cout << "集合 A 与集合 B 的交集为：";
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(AinterB, AinterB.begin()));
    for_each(AinterB.begin(), AinterB.end(), getValue);
    cout << endl;

    cout << "集合 A 与集合 B 的并集为：";
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(AunionB, AunionB.begin()));
    for_each(AunionB.begin(), AunionB.end(), getValue);
    cout << endl;

    cout << "集合 A 的差集为：";
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(AdiffB, AdiffB.begin()));
    for_each(AdiffB.begin(), AdiffB.end(), getValue);
    cout << endl;

    cout << "集合 B 的差集为：";
    set_difference(B.begin(), B.end(), A.begin(), A.end(), inserter(BdiffA, BdiffA.begin()));
    for_each(BdiffA.begin(), BdiffA.end(), getValue);
    cout << endl;

    return 0;
}

// 样例
// 请输入集合 A 的元素个数：5
// 请输入集合 A 的 5 个元素：1 3 2 4 5
// 请输入集合 B 的元素个数：6
// 请输入集合 B 的 6 个元素：3 4 7 2 5 8
// 排序后集合 A 为：1 2 3 4 5 
// 排序后集合 B 为：2 3 4 5 7 8 
// 集合 A 与集合 B 的交集为：2 3 4 5 
// 集合 A 与集合 B 的并集为：1 2 3 4 5 7 8 
// 集合 A 的差集为：1 
// 集合 B 的差集为：7 8 