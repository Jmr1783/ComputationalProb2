/*================================================================================
// Programmer	: Modified by Joseph Rondinelli
// File Name	: Ex12sec2part3.cpp
// Course		: Computational Problem Solving II - CPET
// Description	: Modified program by the book(program 12.4)to demonstrate a small change
 * 				  to the date class that converts the Gregorian values of date into Julian
 * 				  values using a member function. The date class has 3 data members day, month, and year.
 * 				  The class has 2 constructors, one for int's and one for long int's. There are
 * 				  two member functions that show the data stored in the data members (showDate) and
 * 				  take the current values stored and convert them to a single int representation
 * 				  otherwise known as julian form (convrtToJulian).

// Other        : Textbook Problem: Bronson 4th Edition (2012), page 708, Problem 12.3 #3
//================================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

// declaration section
class Date
{
    // Data member declarations
	private:
	int month;
	int day;
	int year;

    //Member function declarations
	public:
	Date(int = 0, int = 0, int = 0); // constructor
	Date(long); // constructor for converting from long to Date
	void showDate();
	int convrtToJulian();
};

// implementation section
Date::Date(int mm, int dd, int yyyy) // constructor
{
	month = mm;
	day = dd;
	year = yyyy;
}

// constructor for converting from long to Date
Date::Date(long findate)
{
	year = int(findate/10000.0);
	month = int((findate - year * 10000.0)/100.0);
	day = int(findate - year * 10000.0 - month * 100.0);
}

// member function to display a date
void Date::showDate()
{
	cout << setfill('0')
		 << setw(2) << month << '/'
		 << setw(2) << day << '/'
		 << setw(2) << year % 100;
	return;
}
// member function for converting to julian form 
int Date::convrtToJulian(){
	int julian_date=0,T=0,MP=0,YP=0;
	if(month<=2){MP=0;YP=year-1;}
	else{MP=int((0.4*month)+2.3);YP=year;}
	T=int(YP/4)-int(YP/100)+int(YP/400);
	julian_date = (365*year)+(31*(month-1))+day+T-MP;
	return julian_date;
}
//*MAIN* constructs 3 dates, 2 are intialized
// then are printed. Two are changed using the long int constructor,
// one is changed using the convrtToJulian member function, 
// the results are then printed after each action.
int main()
{
	Date a; // initialized by the default constructor
	Date b(20141225L); // initialize with a long integer
	Date c(4,1,2012); // initialize with the specified values

	cout << "Dates a, b, and c are ";
	a.showDate();
	cout << ", ";
	b.showDate();
	cout << ", and ";
	c.showDate();
	cout << ".\n";

	a = Date(20120130L); // convert a long to a Date
	cout << "Date a is now ";
	a.showDate();
	cout << endl;


	cout<<a.convrtToJulian();//convert ints to julian form

	b = Date(20120316L); // convert a long to a Date
		cout << endl << "Date a is now ";
		a.showDate();
		cout << endl;

	cout<<b.convrtToJulian();//convert ints to julian form
	return 0;
}
