#include <iostream>
using namespace std;

class A {
public:
	//Constructor Functions
	A(int n): value(n) {
        cout<<"Calling the Constructor of A!"<<endl;
    }
	A():value(0) {
        cout<<"Calling the Default Constructor of A!"<<endl;
    }
	A(A & a): value(a.value) {
        cout<<"Calling the Copy Constructor of A!"<<endl;
    }
	~A() {
        cout<<"Calling the Deconstrucor of A!"<<endl;
    }

	friend int FriendA::get_value(const A &a) const;

private:
	int value;
    static int static_value;
};
int A::static_value = 0;

class FriendA {
public:
	int get_value(const A &a) const {
        return a.value;
    }
	void set_value(A &a, int n) {
        a.value = n;
    }
    int get_static(const A &a) const {
	    return a.static_value;
    }
    void set_static(A &a, int h) {
	    a.static_value = h;
    }
};


int main()
{
	A a;
	A b(1);
	A c(b);
	FriendA friendA;

	//Query
	cout<<"\n"<<endl;
	cout<<"Realization of Private Data Query"<<endl;
	cout<<"private value of a is "<<friendA.get_value(a)<<endl;
	cout<<"private value of b is "<<friendA.get_value(b)<<endl;
	cout<<"private value of c is "<<friendA.get_value(c)<<endl;
    cout<<"private static value is "<<friendA.get_static(a)<<endl;

	//Modification
	cout<<"\n"<<endl;
	cout<<"Realization of Private Data Modification"<<endl;

	friendA.set_value(a,10);
	friendA.set_value(b,20);
	friendA.set_value(c,30);
    friendA.set_static(a, 40);

	cout<<"private x of a is "<<friendA.get_value(a)<<endl;
	cout<<"private x of b is "<<friendA.get_value(b)<<endl;
	cout<<"private x of c is "<<friendA.get_value(c)<<endl;
    cout<<"private static value is "<<friendA.get_static(a)<<endl;


	cout<<"\n"<<endl;
	return 0;
}




