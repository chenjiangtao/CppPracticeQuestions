#include <iostream>
using namespace std;

int count(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int temp, a = 2, b = 1;
    for (int i = 2; i < n; i++) {
        temp = a;
        a += b;
        b = temp;
    }
    return a;
}

int main() {
    int n;
    while (cin >> n) {
        cout << count(n) << endl;
    }
    return 0;
}