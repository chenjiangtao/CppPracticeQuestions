#include <iostream> 
using namespace std;

class Baseclass {
public: 
    Baseclass() {
        cout << "constructor of Baseclass" << endl;
    }
    ~Baseclass() {
        cout << "destructor of Baseclass" << endl;
    }
};

class Derivedclass : public Baseclass {
public: 
    Derivedclass() {
        cout << "constructor of Derivedclass" << endl;
    }
    ~Derivedclass() {
        cout << "destructor of Derivedclass" << endl;
    }
};

int main() {
    Derivedclass d;
    return 0;
}