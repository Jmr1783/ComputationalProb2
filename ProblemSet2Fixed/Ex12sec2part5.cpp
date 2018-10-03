/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex12sec2part5.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Date) that has 3 int data members (month)
			   (day) and (year). The class has 2 member functions that set
			   the value for the Date (setValues), show the Data (showDateGregorian)

			   Constructs a class named (Julian) child of parent Date that has 1 int
			   data member (julian_date).The class has 2 member functions that show
			   the Data (showDateJulian) and a function that converts the parents
			   gregorian values to julian (convrtToJulian).
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 702, Chapter 12.2 #5
============================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

// declaration section

//Parent class declaration
class Date
{
    
	protected:
	//Data member declarations
    int month;
	int day;
	int year;

	public:
	Date(int = 0, int = 0, int = 0); // constructor
	
    //Member function declarations
    void setValues(int,int,int);
	void showDateGregorian();

};

//child class declaration
class Julian : public Date
{
	private:
    //Data member declarations
	int julian_date;

	public:
	Julian(int=0); // constructor
	
    //Member function declarations
    void showDateJulian();
	void convrtToJulian();

};


// implementation section
Date::Date(int mm, int dd, int yyyy) // constructor
{
	month = mm;
	day = dd;
	year = yyyy;
}

//Member function that displays Date in Gregorian Form
void Date::showDateGregorian()
{
	cout << setfill('0')
		 << setw(2) << month << '/'
		 << setw(2) << day << '/'
		 << setw(2) << year % 100<<endl;
	return;
}

//Member function that changes values of Date data members
void Date::setValues(int mm, int dd, int yyyy)
{
	month = mm;
	day = dd;
	year = yyyy;
	return;
}

Julian::Julian(int date) // constructor
{
	julian_date = date;
}

// Member function that displays Julian data members 
void Julian::showDateJulian()
{
	cout<<"Julian: "
	    <<julian_date
		<<endl;
	return;
}

//Member function that converts Date data members to julian
void Julian::convrtToJulian(){
	int T=0,MP=0,YP=0;
	if(month<=2){MP=0;YP=year-1;}
	else{MP=int((0.4*month)+2.3);YP=year;}
	T=int(YP/4)-int(YP/100)+int(YP/400);
	julian_date = (365*year)+(31*(month-1))+day+T-MP;
	return;
}

/* MAIN: Creates 2 dates in gregorian form and displays them, then
         proceeds ro convert them to julian form and displays the results
*/
int main()
{
	Julian j1;
	j1.setValues(1,31,2012);
	j1.showDateGregorian();
	j1.convrtToJulian();
	j1.showDateJulian();
	j1.setValues(3,16,2012);
    j1.showDateGregorian();
	j1.convrtToJulian();
	j1.showDateJulian();

	return 0;
}
