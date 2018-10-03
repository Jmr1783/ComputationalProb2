/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part6-9.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (IntDate) that has 1 int data member (date).
  	  	  	   The class has four member functions that set the values for the Date (setData),
  	  	  	   show the Data (showData) in month/day/year.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 631, Problem 11.1 #9
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class IntDate
{
	private:
		int date;
	public:
		IntDate (int = 0);
		void setData();
		void showData();


};
// end of declaration section

// implementation section
IntDate::IntDate(int d)
{
	date = d;
}

void IntDate::setData()
{
	int year=0,month=0,day=0;
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day:";
	cin >> day;
	date =(year*100000)+(month*100)+day;
}

void IntDate::showData()
{
	//Date single int to multi int conversion by powers of 10
	int y = date/100000
	,m=(date-(y*100000))/100, d=date-(m*100+y*100000);
	cout<<"The Date is: "<< date << endl
	<< m << '/'<< d << '/' << y << endl;
}


// end implementation section

/*MAIN:
 * In main a IntDate data type was set with values with
 * setData() and then were printed with showdata()
 */
int main()
{

	IntDate test;

	test.setData();
	test.showData();

	return 0;
}
