/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex12Project1.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Fractions) that has 2 int data members
 	 	 	   (num) and (denom). The class has 2 iomanip overload functions that set
			   the values and one that prints the fraction out,
			   and 4 overload functions that send fraction datatypes to their own add, subtract
			   ,multiply and divde functions.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 723, Chapter 12 Project #1
============================================================================*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// declaration section
class Fractions {
	private:
    int num;       // declare realPart as a double variable
	int denom;  // declare imaginaryPart as a double variable

  public:
	Fractions(int numer = 1, int dumer = 1)    // inline constructor
  	  {num = numer; denom = dumer;}
	Fractions operator+(const Fractions&);  // prototype for the addition operator
	Fractions operator-(const Fractions&);  // prototype for the subtraction operator
	Fractions operator*(const Fractions&);  // prototype for the multiplication operator
	Fractions operator/(const Fractions&); // prototype for the divide operator
	friend ostream& operator<<(ostream&, const Fractions&);
	friend istream& operator>>(istream&, Fractions&);

};   // end of class declaration
// implementation section

//Member functions overloads for +-*/ input and ouput
Fractions Fractions::operator+(const Fractions& fract1)
{
	Fractions calculation;
	calculation.num = (num*fract1.denom) + (denom*fract1.num);
	calculation.denom = (denom* fract1.denom);
	return (calculation);
}

Fractions Fractions::operator-(const Fractions& fract2)
{
	Fractions calculation;
	calculation.num = (num*fract2.denom) - (denom*fract2.num);
	calculation.denom = denom*fract2.denom;
	return (calculation);
}

Fractions Fractions::operator*(const Fractions& fract3)
{
	Fractions calculation;
	calculation.num = num*fract3.num;
	calculation.denom = denom*fract3.denom;
	return (calculation);
}

Fractions Fractions::operator/(const Fractions& fract4)
{
	Fractions calculation;
	calculation.num = num*fract4.denom;
	calculation.denom = denom*fract4.num;
	return (calculation);
}

istream& operator>>(istream& in, Fractions& fract) {
	char dummy = ' ';
	cout << "Input a fraction in form of <a>/<b>: "<<endl;
	cin>> fract.num >> dummy >> fract.denom;
	return in;
}
ostream& operator<<(ostream& out, const Fractions & fract) {
	cout << "Fraction: "<<fract.num<<'/'<<fract.denom<<endl;
	return out;
}
//End of member functions overloads for +-*/ input and ouput

/*MAIN: takes 2 fractions and does +,-,*, / operations on each fraction 
        object while using input ouput overloads
*/
int main() {
	Fractions fraction1,fraction2,result;
	cin >> fraction1;
	cout << fraction1;
	cin >> fraction2;
	cout << fraction2;
	cout << "ADD: ";
	result = fraction1+fraction2;
	cout << result;
	cout << endl; cout << "Sub: ";
	result = fraction1-fraction2;
	cout << result;
	cout << endl; cout << "Multi: ";
	result = fraction1*fraction2;
	cout << result;
	cout << endl; cout << "Divide: ";
	result = fraction1/fraction2;
	cout << result;
	cout << endl;
  return 0; }
