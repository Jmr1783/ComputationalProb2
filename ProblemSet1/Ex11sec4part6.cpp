/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex 11sec4part6-10
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Date) that has 3 int data members (year)
			   , (month) and (day). The class has two member functions that that find
			   the numerical day of the week starting with staturday at 0 and returns
			   that value then that is sent into a function to find out if date is a week
			   day (isWeekday) then return a true or false.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 672, Problem 11.4 #6
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
		bool isWeekday(int);
		int dayOfWeek();

};
// end of declaration section

// implementation section
Date::Date(int m,int d,int y)
{
	day = d;
	month = m;
	year = y;
}

bool Date::isWeekday(int calc){
	int answer = false;
	if((calc>=2)&&(calc<=6)){
		answer = true;
	}
	return answer;
}

int Date::dayOfWeek(){
	// Zeller’s algorithm
	int dd=0,T=0,cent=0;
	if(month<3){
		month=month+12;
		year=year-1;
	}
	cent = int(year/100);
	year=year%100;
	T= day + int(26*(month+1)/10) +year+int(year/4)+int(cent/4)-(2*cent);
	dd=T%7;
	if(dd<0){
	dd=dd+7;
	}
	// End of Zeller’s algorithm
	return dd;
}



// end implementation section

int main()
{
	Date d1(3,12,2011),d2(3,15,2011);

	cout << "(1 for weekday & 0 for no)"<< endl
			<< "Date 1 is: "
			<< d1.isWeekday(d1.dayOfWeek())<< endl
	        << "Date 2 is: " << d2.isWeekday(d2.dayOfWeek())<< endl;


	return 0;
}
