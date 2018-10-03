/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11secProject_Part1-4.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Pol_coord) that has 2 double data members
 	 	 	   (dist) and (theta). The class has one member function that set
			   the value for the x and y coordinates and converts them to polar values
			   then prints them (convToPolar);
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 681, Problem 11.Project #1
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Pol_coord
{
	private:
		double dist,theta;
	public:
		Pol_coord (double = 0.0, double = 0.0);
		void convToPolar();
};
// end of declaration section

// implementation section
Pol_coord::Pol_coord (double d,double t)
{
	dist = d;
	theta = t;
}

void Pol_coord::convToPolar(){
	double x =0.0,y=0.0;
	cout << "x: "; cin >> x; cout <<endl;
	cout << "y: "; cin >> y; cout <<endl;
	dist = sqrt((x*x)+(y*y));
	theta = atan(y/x);
	cout << "Distance: " << dist <<endl
	<< "Theta: " << theta << endl;
}
// end implementation section

int main()
{
	Pol_coord test;
	test.convToPolar();


	return 0;
}



