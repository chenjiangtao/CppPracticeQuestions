#include <iostream> 
#include <deque> 
using namespace std;

void f(deque<int> x, deque<int> y) {
    while (!y.empty()) {
        x.push_back(y.front());
        y.pop_front();
    }
}

int main() {
    deque<int> A, B;
    A.clear();
    B.clear();
    for (int i = 0; i < 5; i++) {
        A.push_back(i);
        B.push_back(i);
    }
    f(A, B);
    deque<int>::iterator iter;
    for (iter = A.begin(); iter != A.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}