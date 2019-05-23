#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.1415927;

class Shape{
protected:
	int numside; //Protected: No need for public portal for derived classes to visit
public:
	//Constructors and Destructor
    Shape(int n):numside(n) {cout<<"Constructed a Shape with numside = "<<numside<<endl;}
	Shape(): numside(0) {cout<<"Default Constructed a Shape with numside = "<<numside<<endl;}
	Shape(Shape & S):numside(S.numside) {cout<<"Copy Constructed a Shape with numside = "<<numside<<endl;}
    ~Shape() {cout<<"Deconstructed a Shape!"<<endl;}

	//Functions
	virtual double Area()= 0; 
};

class Square: public Shape{
private:
	double side;
	double area;

public:
	//Constructors and Deconstructor
    Square(double s):Shape(4), side(s),area(s*s){cout<<"Constructed a Square with side = "<<side<<endl;}
	Square(Square & S): Shape(S), side(S.side), area(S.area) {cout<<"Copy Constructed a Square with side = "<<side<<endl;}
	Square():Shape(4),side(1),area(1) {cout<<"Default Constructed a Square with side = "<<side<<endl;}
    ~Square() {cout<<"Deconstructed a Square!"<<endl;}

	//Functions
	double Area(){return area;} 
	double getSide(){return side;}
};

class Rectangle: public Shape{
private:
	double sideA;
	double sideB;
	double area;
public:
	//Constructors and Deconstructor
    Rectangle(double a, double b):Shape(4), sideA(a), sideB(b),area(a*b){cout<<"Constructed a Rectangle with sideA = "<<sideA<<"and sideB = "<<sideB<<endl;}
	Rectangle(Rectangle & R): Shape(R), sideA(R.sideA), sideB(R.sideB),area(R.area){cout<<"Copy Constructed a Rectangle with sideA = "<<sideA<<"and sideB = "<<sideB<<endl;}
	Rectangle():Shape(4),sideA(1),sideB(1),area(1) {cout<<"Default Constructed a Rectangle with sideA = "<<sideA<<"and sideB = "<<sideB<<endl;}
    ~Rectangle() {cout<<"Deconstructed a Rectangle!"<<endl;}

	//Functions
	double Area(){return area;} 
	double getsideA(){return sideA;}
	double getsideB(){return sideB;}
};

class Circle: public Shape{
private:
	double radius;
	double area;
public:
	//Constructors and Deconstructor
	Circle(double r):Shape(INT_MAX), radius(r), area(PI*r*r){cout<<"Constructed a Circle with radius ="<<radius<<endl;}
	Circle(Circle & C): Shape(C), radius(C.radius),area(C.area){cout<<"Copy Constructed a Circle with radius ="<<radius<<endl;}
	Circle():Shape(INT_MAX),radius(1),area(PI){cout<<"Default Constructed a Circle with radius ="<<radius<<endl;}
    ~Circle() {cout<<"Deconstructed a Circle!"<<endl;}

	//Functions
	double Area(){return area;} 
	double getRadius(){return radius;}
};


int main() {
    Square mySquare(4.21);
	Rectangle myRectangle (2.3,3.4);
	Circle myCircle(2);

	Shape* array[3];
	//Notice that we cannot define an object of a abstract class, but we can define its pointer!
	array[0] = & mySquare;
	array[1] = & myRectangle;
	array[2] = & myCircle;

	for (int i = 0; i < 3; i ++){
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<array[i] -> Area()<<endl;
	}

	return 0;
}

