/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex12Project3.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Rectangle) that has 2 double data members (length)
			   and (width). The class has 3 member functions that set
			   the value for the Rectangle (setDataRectangle), show the Data (showDataRectangle)
			   in length and width, and calculate the area with length and width (area)
			   and return a value.
			   Constructs a class named (Box) child of parent Rectangle that has 1 double data member (depth).
			   The class has four member functions that set
			   the value for the Rectangle (setDataBox), show the Data (showDataBox)
			   in length, width and depth, calculate the surface area with length, width
			   and depth (area) and return a value, and calculate the volume with length
			   ,width and depth (volume) and return a value.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 724, Chapter 12 Project 3
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Rectangle //Parent class
{
	protected:
    //Data member declarations
	double l,w;

	public:
	Rectangle(double=0, double=0); // constructor
	
    //Member function declarations
    void setValuesRectangle(double,double);
	double area(Rectangle&);
	void showDataRectangle();

};

class Box : public Rectangle //child class of parent 
{
	private:
	//Data member declarations
    double depth;

	public:
	Box(double=0); // constructor
	
    //Member function declarations
    void setValuesBox(double,double,double);
	void showDataBox();
	double area(Box&);
	double volume(Box&);


};


// implementation section
Rectangle::Rectangle(double L, double W) // constructor
{
	l = L;
    w = W;
	return;
}

//member function that calculates area of object rectangle
double Rectangle::area(Rectangle& r){
	return r.w*r.l;
}

//member function that displays rectangle class data
void Rectangle::showDataRectangle()
{
	cout << "L= "<<l<<" W= "<<w<<endl;
	return;
}

//member function that sets rectangle class data
void Rectangle::setValuesRectangle(double L, double W)
{
	l = L;
    w = W;
	return;
}

Box::Box(double D){ //constructor
	depth = D;
}

//member function that sets box class data
void Box::setValuesBox(double L, double W,double D)
{
	l = L;
	w = W;
    depth = D;
	return;
}

//member function that displays box class data
void Box::showDataBox()
{
	cout << "Length= "<<l<<" Width= "<<w<<" Depth= "<<depth<<endl;
	return;
}

//member function that calculates box object areas
double Box::area(Box& b){
	double area = (2*b.l*b.w)+(2*b.l*b.depth)+(2*b.w*b.depth);
	return area;
}

//member function that calculates box object volumes
double Box::volume(Box& b){
	double volume = b.l*b.w*b.depth;
	return volume;
}


/*MAIN: Creates a box and rectangle with initial values and either calculates the area and/or volume   of      the object then prints the results. 

*/
int main()
{
	Box c1,temp;
	Rectangle r1,tempRec;
	c1.setValuesBox(2.0,5.0,2.0);
	r1.setValuesRectangle(2.0,3.0);

	cout << "Rect 1: " << endl;
	r1.showDataRectangle();
	cout << "Area 1: "<< tempRec.area(r1) << endl;

	cout << "Box 1: " << endl;
	c1.showDataBox();
	cout << "Area 1: "<< temp.area(c1) << endl;
	cout << "Volume 2: "<< temp.volume(c1) << endl;


	return 0;
}


