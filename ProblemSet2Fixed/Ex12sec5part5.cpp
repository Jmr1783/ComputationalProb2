/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex12sec5part5.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named Point that has 2 data members (x) and (y)
 	 	 	   which are coordinates. This class has 4 member functions which set
 	 	 	   values to the data members (setValuesPoint), show what's stored in those data members
 	 	 	   (showDataPoints), one that uses x and y to calculate the area (area) and one to
 	 	 	   calculate the distance between 2 points.
 	 	 	   Also a child class of Point is created (Circle) to create circles which share data members of
 	 	 	   point and add a radius data member to specify its size. This class has 3 member functions which set
 	 	 	   values to the data members (setValuesCircle), show what's stored in those data members
 	 	 	   (showDataCircle),and one override function that uses radius to calculate the area of the circle.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 716, Chapter 12 section 5 problem 5
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double pi = 3.14159265359;
// declaration section
class Point // Parent
{
	protected:
	//Data member declarations
    double x,y;

	public:
	Point(double=0, double=0); // constructor
    
    //Member function declarations
	void setValuesPoint(double,double);
	double area();
	double distance(Point&,Point&);
	void showDataPoints();

};

class Circle : public Point // Child of Point class
{
	private:
    //Data member declarations
	int radius;

	public:
	Circle(double=0); // constructor
	
    //Member function declarations
    void setValuesCircle(double,double,double);
	void showDataCircle();
	double area(Circle&);


};


// implementation section
Point::Point(double X, double Y) // constructor
{
	x = X;
    y = Y;
	return;
}

//Member function that just returns the area of a 1 dimension object = 0
double Point::area(){return 0;}

//Member function that takes in two objects and finds their distance
double Point::distance(Point& p1,Point& p2){
	double distance = sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
	return distance;
}

//Member function that displays data from point class
void Point::showDataPoints()
{
	cout << '('<< x <<','<< y <<')'<<endl;
	return;
}

//Member function that changes values of class point
void Point::setValuesPoint(double X, double Y)
{
	x = X;
    y = Y;
	return;
}

Circle::Circle(double r)//constructor 
{
	radius = r;
}

//Member function that changes values of class circle
void Circle::setValuesCircle(double X, double Y,double r)
{
	x = X;
    y = Y;
    radius =r;
	return;
}

//Member function that displays data from circle class
void Circle::showDataCircle()
{
	cout << '('<< x <<','<< y <<") r = "<< radius <<endl;
	return;
}

//Member function that returns the area of a circle object
double Circle::area(Circle& c){
	double area = pi*pow(c.radius,2);
	return area;
}
/*MAIN: Creates two point objects and two circle abjects with initial values. 
        Then the area within and distance between objects are calculated and outputed as a result 

*/
int main()
{
	Point p1,p2, temp_point;
	Circle c1,c2,temp_circle;

	p1.setValuesPoint(1.0,3.0);
	p2.setValuesPoint(6.0,7.0);
	cout << "Point 1: " << endl;
	p1.showDataPoints();
	cout << "Point 2: " << endl;
	p2.showDataPoints();
	cout << "Area: "<< temp_point.area() << endl;
	cout << "Distance between points: "<< temp_point.distance(p1,p2) << endl;

	c1.setValuesCircle(2.0,5.0,2.0);
	c2.setValuesCircle(1.0,3.0,4.0);
	cout << "Circle 1: " << endl;
	c1.showDataCircle();
	cout << "Area 1: "<< temp_circle.area(c1) << endl;
	cout << "Circle 2: " << endl;
	c2.showDataCircle();
	cout << "Area 2: "<< temp_circle.area(c2) << endl;
	cout << "Distance between Circles: " << temp_circle.distance(c1,c2) << endl;

	return 0;
}
