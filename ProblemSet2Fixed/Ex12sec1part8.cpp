/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex12sec1part8.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Time) that has 3 int data members (secs)
			   , (mins) and (hours). The class has two member functions that set
			   the value for the time (setTimeValues) and show the time (showData)
			   in hours, mins, secs;The class also has 2 overload operators that
			   control how objects are printed and set.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 693, Problem 12.1 #8
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Time
{
        //Data member declarations
		private:
			int secs,mins,hours;
		//Member function declarations
        public:
			Time (int = 10, int = 10,int = 10);
			void setTimeValues(int,int,int);
            //overload declarations
			friend ostream& operator<<(ostream&, const Time&); 
			friend istream& operator>>(istream&, Time&);
};
	// end of declaration section

	// implementation section
	Time::Time (int s, int m,int h)
	{
		secs = s;
		mins = m;
		hours = h;
	}

    //member function for changing data members
	void Time::setTimeValues(int s,int m, int h)
	{
		secs = s;
		mins = m;
		hours = h;
	}
    //overload insertion operator for outputing time values
	ostream& operator<<(ostream& out, const Time& time){
		cout << "The time is: " << time.hours << " : " << time.mins << " : " << time.secs;
	return (out);
	}
    //overload insertion operator for inputing time values
	istream& operator>>(istream& in, Time& time){
		cin >> time.hours >> time.mins >> time.secs;
		return (in);
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
	cin>>t;
	cout<<t;

	return 0;
}
