#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> _v) {
    for (int i = 0; i < _v.size(); ++i) {
        cout << _v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    v.clear();
    for (int i = 1; i < 9; i++) {
        v.push_back(i);
    }
    vector<int>::iterator iter = find(v.begin(), v.end(), 3);
    sort(v.begin(), v.end());
    output(v);
    sort(v.begin(), v.end(), greater<int>());
    output(v);
    return 0;
}