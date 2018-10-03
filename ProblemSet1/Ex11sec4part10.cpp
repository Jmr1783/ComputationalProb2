/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex 11sec4part6-10
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Date) that has 3 int data members (year)
			   , (month) and (day). The class has two member functions that that finds
			   the next day of the week 1 day later and shifts to that point (nextDay) and
			   then prints out the date with (showDate)
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 673, Problem 11.4 #10
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Date
{
	private:
		int year,month,day;
	public:
		Date (int = 0,int = 0,int=0);
		void nextDay();
		void showDate();

};
// end of declaration section

// implementation section
Date::Date(int m,int d,int y)
{
	day = d;
	month = m;
	year = y;
}

void Date::nextDay(){
	if (30 > day){day=day+1;}
	else
	{
	  if (12 > month){day = 0;month=month+1;}
		else{day = 0;month = 1;year=year+1;}
	}
}

void Date::showDate(){
	cout << "Current Date: " << month << "/" << day << "/" << year << endl;
}
// end implementation section

int main()
{
	Date d1(11,28,2011);
	d1.showDate();
	for(int i = 0;i<=33;i++){
		d1.nextDay();
	    d1.showDate();
	}
	return 0;
}
