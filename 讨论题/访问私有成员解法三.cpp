#include <iostream>
using namespace std;

class A;

class FriendA {
public:
	int get_value(A &a);
	void set_value(A &a, int n);
};

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
	friend int FriendA::get_value(A &a);
private:
	int value;
};

int FriendA::get_value(A &a) {
	return a.value;
}

// void FriendA::set_value(A &a, int n) {
// 	a.value = n;
// }


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


	cout<<"\n"<<endl;
	return 0;
}




