/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part6-9.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Time) that has 3 int data members (secs)
			   , (mins) and (hours). The class has two member functions that set
			   the value for the time (setTimeValues) and show the time (showData)
			   in hours, mins, secs;
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 631, Problem 11.1 #6
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Time
{
	private:
		int secs,mins,hours;
	public:
		Time (int = 0, int = 0,int = 0);
		void setTimeValues(int,int,int);
		void showData();
};
// end of declaration section

// implementation section
Time::Time (int s, int m,int h)
{
	secs = s;
	mins = m;
	hours = h;
}

void Time::setTimeValues(int s,int m, int h)
{
	secs = s;
	mins = m;
	hours = h;
}

void Time::showData()
{
	cout << "The time is: " << hours << " : " << mins << " : " << secs;
}

// end implementation section

/*MAIN:
 * In main a time data type was set with values with
 * setTimeValues() and then were printed with showdata()
 */
int main()
{

	Time t;

	t.setTimeValues(2,5,7);
	t.showData();

	return 0;
}
