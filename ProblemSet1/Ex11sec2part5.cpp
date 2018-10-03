/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part5-14.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Rectangle) that has 2 double data members (length)
			   and (width). The class has four member functions that set
			   the value for the Rectangle (setData), show the Data (showData)
			   in length and width, calculate the perimeter with length and width (perimeter)
			   and print a value, and calculate the area with length and width (area)
			   and print a value.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 631, Problem 11.1 #5
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
		Rectangle (double = 1.0 , double = 1.0);
		void perimeter();
		void area();
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

void Rectangle::perimeter()
{
	double p = 0.0;
	p = ((2.0*length) + (2.0*width));
	cout << "Perimeter: " << p << endl;
}

void Rectangle::area()
{
	double a = 0.0;
	a = length*width;
	cout << "Area: " << a << endl;
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
	cout << "Length = " << length << "\nWidth = "<< width << endl;
}


// end implementation section

/*MAIN:
 * In main a Rectangle data type was set with values with
 * setData(),then were printed with showdata() and the
 * perimeter and area were calculated then printed in their functions
 */
int main()
{

	Rectangle r;

	r.setData();
	r.showData();
	r.perimeter();
	r.area();

	return 0;
}
