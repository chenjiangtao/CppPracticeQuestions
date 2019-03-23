#include <iostream>
using namespace std;

float Convert(float TempFer) {
    return (TempFer - 32) * 5 / 9;
}

int main() {
    float f;
    cin >> f;
    cout << Convert(f) << endl;
    return 0;
}