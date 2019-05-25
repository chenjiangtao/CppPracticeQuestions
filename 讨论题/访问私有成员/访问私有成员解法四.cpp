#include <iostream>
using namespace std;


class Point{
public:
	//Constructor Functions
	Point(int vx, int vy, int vz): x(vx), y(vy), z(vz) {
        cout<<"Calling the Constructor of Point!"<<endl;
    }
	Point():x(0), y(0), z(0) {
        cout<<"Calling the Default Constructor of Point!"<<endl;
    }
	Point(Point & p): x(p.x), y(p.y), z(p.z) {
        cout<<"Calling the Copy Constructor of Point!"<<endl;
    }
	~Point() {
        cout<<"Calling the Deconstrucor of Point!"<<endl;
    }
	//Query and Modification of Private Variables
	int get_x() {
        return x;
    }
	int get_y() {
        return y;
    }
	int get_z() {
        return z;
    }
    static int get_static() {
        return static_value;
    }
    int get_protected() {
        return protected_value;
    }

    int public_value = 88;	

private:
	int x;
	int y;
	int z;
    static int static_value;

protected: 
    int protected_value = 99;
};
int Point::static_value = 100;


int main()
{
	Point P1(1,2,3);

	cout<<"\n"<<endl;
	cout<<"Before Magical Modification: "<< endl;
    cout<<"The public_value of P1 is "<<P1.public_value<<endl;
	cout<<"The Real x of P1 is "<<P1.get_x()<<endl;
	cout<<"The Real y of P1 is "<<P1.get_y()<<endl;
	cout<<"The Real z of P1 is "<<P1.get_z()<<endl;
    cout<<"The static value of Point is "<<Point::get_static()<<endl;
    cout<<"The protected value of Point is"<<P1.get_protected()<<endl;

	//Magic Begins Here
	int *p = (int*) (& P1);
	cout<<"\n"<<endl;
	cout<<"Magic can do Query of Private Data!"<<endl;
	cout<<"Magic says the x of P1 is "<<p[1]<<endl;
	cout<<"Magic says the y of P1 is "<<p[2]<<endl;
	cout<<"Magic says the z of P1 is "<<p[3]<<endl;
    cout<<"Magic says the protected value of P1 is "<<p[4]<<endl;
    
    

	p[1] = 10;
	p[2] = 20;
    p[3] = 30;
    p[4] = 199;

	//Results of Magic
	cout<<"\n"<<endl;
	cout<<"Magic can change the value of Private Data!"<<endl;
	cout<<"Magic changes the x of P1 to "<<P1.get_x()<<endl;
	cout<<"Magic changes the y of P1 to "<<P1.get_y()<<endl;
	cout<<"Magic changes the z of P1 to "<<P1.get_z()<<endl;
    cout<<"Magic changes the protected value of Point to "<<P1.get_protected()<<endl;

	//Comments
	//First,  & P1 gets the address of this object. 
	//Second, (int *) creates a pointer that points to this address
	//Third,  assign this pointer to pointer p
	//We can have access to the private data applying a more low-layer method

	//更加精致的解释是：
	//类的对象的存储的原理大概是，对象这个变量本身有一个对象的首地址（像个线头），对象中存储的其实是其各个成员的地址，类似是一个数组
	//这些成员的存储空间是连续的，所以只要知道首地址，往后读取就是各个成员
	//& P1取得了P1这个对象的首地址
	//（int*）P1则是创建了一个int 类型的数组（或者说是指针，这两者是等价的）
	//（int*）规定了读取的时候会4位一读
	//然后把这个指针赋值给p

	cout<<"\n"<<endl;
	return 0;
}

