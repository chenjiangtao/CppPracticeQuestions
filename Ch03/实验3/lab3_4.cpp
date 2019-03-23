#include <iostream> 
using namespace std;

long long pow(int x, int y) {
    if (y == 0) return 1;
    return x * pow(x, y - 1);
}

int main() {
    int a, b;
    cin >> a >> b;
    if (b < 0) exit(0);
    cout << pow(a, b) << endl;
    return 0;
}