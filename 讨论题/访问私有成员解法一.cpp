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
	//Query and Modification of Private Variables
	int get_value() const {
        return value;
    }
	void set_value(int n) {
        value = n;
    }
	static int get_static() {
        return value_static;
    }
	static void set_static(int h) {
        value_static = h;
    }
private:
	int value;
	static int value_static;
};

int A::value_static = 0;


int main()
{
	A a;
	A b(1);
	A c(b);

	//Query
	cout<<"\n"<<endl;
	cout<<"Realization of Private Data Query"<<endl;
	cout<<"private value of a is "<<a.get_value()<<endl;
	cout<<"private value of b is "<<b.get_value()<<endl;
	cout<<"private value of c is "<<c.get_value()<<endl;
	cout<<"private static value is "<<A::get_static()<<endl;

	//Modification
	cout<<"\n"<<endl;
	cout<<"Realization of Private Data Modification"<<endl;


	a.set_value(10);
	b.set_value(20);
	c.set_value(30);
	A::set_static(40);


	cout<<"private x of a is "<<a.get_value()<<endl;
	cout<<"private x of b is "<<b.get_value()<<endl;
	cout<<"private x of c is "<<c.get_value()<<endl;
	cout<<"private static value is "<<A::get_static()<<endl;


    cout<<"\n"<<endl;
	return 0;
}
