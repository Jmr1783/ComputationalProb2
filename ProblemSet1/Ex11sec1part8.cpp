/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part6-9.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Rectangle) that has 2 double data members (length)
			   and (width). The class has four member functions that set
			   the value for the Rectangle (setData), show the Data (showData)
			   in length and width, calculate the perimeter with length and width (perimeter)
			   and return a value, and calculate the area with length and width (area)
			   and return a value.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 631, Problem 11.1 #8
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Rectangle
{
	private:
		double length, width;
	public:
		Rectangle (double = 0.0 , double = 0.0);
		double perimeter(double,double);
		double area(double,double);
		void setData();
		void showData();


};
// end of declaration section

// implementation section
Rectangle::Rectangle(double l, double w)
{
	length = l;
	width = w;
}

double Rectangle::perimeter(double l,double w)
{
	double p = 0.0;
	p = (2.0*l) + (2.0*w);
	return p;
}

double Rectangle::area(double l,double w)
{
	double a = 0.0;
	a = l*w;
	return a;
}

void Rectangle::setData()
{
	cout << "Length: ";
	cin >> length;
	cout << "Width: ";
	cin >> width;
}

void Rectangle::showData()
{
	cout << "Length = " << length << "\nWidth = "<< width << "\nPerimeter = " << perimeter(length,width) << "\nArea = " << area(length,width) << endl;
}


// end implementation section

/*MAIN:
 * In main a Rectangle data type was set with values with
 * setData() and then were printed with showdata()
 */
int main()
{

	Rectangle r;

	r.setData();
	r.showData();

	return 0;
}
