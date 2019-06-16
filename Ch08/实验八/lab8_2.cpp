#include <iostream> 
using namespace std;

class vehicle {
public: 
    int n;
    vehicle (int _n) : n(_n) {}
    vehicle () {
        n = 0;
    }
    virtual ~vehicle() {}
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

class bicycle : public vehicle {
public: 
    bicycle () {
        n = 2;
    }
    ~bicycle () {}
    virtual void Run() {
        cout << "bicyble is running" << endl;
    }
    virtual void Stop() {
        cout << "bicycle stops" << endl;
    }
};

class motorcar : public vehicle {
public: 
    motorcar () {
        n = 4;
    }
    ~motorcar () {}
    virtual void Run() {
        cout << "motorcar is running" << endl;
    }
    virtual void Stop() {
        cout << "motorcar stops" << endl;
    }
};

int main() {
    vehicle* b = new bicycle;
    vehicle* m = new motorcar;
    b->Run();
    b->Stop();
    m->Run();
    m->Stop();
    delete b;
    delete m;
    return 0;
}