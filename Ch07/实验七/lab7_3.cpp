#include <iostream> 
using namespace std;

class vehicle {
protected: 
    int n;
public: 
    vehicle () {
        cout << "c of v" << endl;
    }
    virtual ~vehicle () {
        cout << "d of v" << endl;
    }
};

class bicycle : public vehicle {
public: 
    bicycle () {
        cout << "c of b" << endl;
        n = 2;
    }
    ~bicycle () {
        cout << "d of b" << endl;
    }
};

class motorcycle : public vehicle {
public: 
    motorcycle () {
        cout << "c of m" << endl;
        n = 4;
    }
    ~motorcycle () {
        cout << "d of m" << endl;
    }
};

int main() {
    bicycle b;
    motorcycle m;
    return 0;
}