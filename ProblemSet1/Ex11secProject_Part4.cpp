/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11secProject_Part1-4.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Fractions) that has 2 int data members
 	 	 	   (num) and (denom). The class has two member function that set
			   the values (assignNewValues), one that prints the fraction out (showFractionValues),
			   and 4 overload functions that send fraction datatypes to their own add, subtract
			   ,multiply and divde functions.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 681, Problem 11.Project #4
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
	void showFractionValues();                 // accessor prototype
	void assignNewValues(int,int);  // inline mutator
	Fractions operator+(const Fractions&);  // prototype for the addition operator
	Fractions operator-(const Fractions&);  // prototype for the subtraction operator
	Fractions operator*(const Fractions&);  // prototype for the multiplication operator
	Fractions operator/(const Fractions&);  // prototype for the divide operator
};   // end of class declaration
// implementation section

void Fractions::showFractionValues(){cout << "Fraction: "<<num<<'/'<<denom<<endl;}
void Fractions::assignNewValues(int n,int d){num = n;denom=d;}

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

int main() {
	Fractions fraction1(6,8),fraction2(4,5),result;
	fraction1.showFractionValues();
	fraction2.showFractionValues();
	cout << "ADD: ";
	result = fraction1+fraction2;
	result.showFractionValues();
	cout << endl; cout << "Sub: ";
	result = fraction1-fraction2;
	result.showFractionValues();
	cout << endl; cout << "Multi: ";
	result = fraction1*fraction2;
	result.showFractionValues();
	cout << endl; cout << "Divide: ";
	result = fraction1/fraction2;
	result.showFractionValues();
	cout << endl;
  return 0; }



