// 描述
// 编写一个具有以下原型的函数模板：
// template<class T> 
// void exchange(list<T> & l1, class list<T>::iterator p1, list<T> & l2, class list<T>::iterator p2);
// 该模板用于将 l1 链表的 [p1, l1.end()) 区间和 l2 链表的 [p2, l2.end()) 区间的内容交换。
// 在主函数中调用该模板，以测试该模板的正确性。

#include <iostream> 
#include <list>
#include <cassert>
using namespace std; 

template<typename T>
void exchange(list<T>& _l1, typename list<T>::iterator _p1, list<T>& _l2, typename list<T>::iterator _p2) {
    list<int> tempList;
    tempList.clear();
    tempList.splice(tempList.begin(), _l1, _p1, _l1.end());
    _l1.splice(_l1.end(), _l2, _p2, _l2.end());
    _l2.splice(_l2.end(), tempList, tempList.begin(), tempList.end());
}

void printList(int l) {
    cout << " -> " << l;
}

typedef list<int> LIST;

int main() {
    int size_1, size_2;
    LIST l1, l2;

    cout << "请输入 list 1 的结点数：";
    cin >> size_1;
    cout << "请输入 list 1 的结点： ";
    for(int i = 0; i < size_1; i++) {
        int num;
        cin >> num;
        l1.push_back(num);
    }
    
    cout << "请输入 list 2 的结点数：";
    cin >> size_2;
    cout << "请输入 list 2 的结点：";
    for(int i = 0; i < size_2; i++) {
        int num;
        cin >> num;
        l2.push_back(num);
    }

    list<int>::iterator p1 = l1.begin();
    int m, n;
    cout << "请输入 list 1 开始交换的结点位置：";
    cin >> m;
    assert(m > 0 && m < size_1);
    for (int i = 1; i < m; i++) {
        p1++;
    }

    list<int>::iterator p2 = l2.begin();
    cout << "请输入 list 2 开始交换的结点位置：";
    cin >> n;
    assert(n > 0 && n < size_2);
    for (int i = 1; i < n; i++) {
        p2++;
    }

    cout << "交换前：" << endl;
    cout << "list 1: head";
    for_each(l1.begin(), l1.end(), printList);
    cout << endl;
    cout << "list 2: head";
    for_each(l2.begin(), l2.end(), printList);
    cout << endl;

    exchange(l1, p1, l2, p2);

    cout << "交换后：" << endl;
    cout << "list 1: head";
    for_each(l1.begin(), l1.end(), printList);
    cout << endl;
    cout << "list 2: head";
    for_each(l2.begin(), l2.end(), printList);
    cout << endl;

    return 0;
}

// 输入
// 请输入 list 1 的结点数：4
// 请输入 list 1 的结点： 0 1 2 3
// 请输入 list 2 的结点数：6
// 请输入 list 2 的结点：6 7 8 9 10 11
// 请输入 list 1 开始交换的结点位置：3
// 请输入 list 2 开始交换的结点位置：2
// 输出
// 交换前：
// list 1: head -> 0 -> 1 -> 2 -> 3
// list 2: head -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
// 交换后：
// list 1: head -> 0 -> 1 -> 7 -> 8 -> 9 -> 10 -> 11
// list 2: head -> 6 -> 2 -> 3