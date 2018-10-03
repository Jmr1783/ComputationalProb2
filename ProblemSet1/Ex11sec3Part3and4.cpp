/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec3part3and4.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Complex) that has 2 double data members (realPart)
			   and (imaginaryPart). The class has two member functions that set
			   the value for the Complex (assignNewValues), show the Data (showComplexValues)
			   in realPart and imaginaryPart. And aswell as 3 overload function for addition,
			   subtraction and multiplication.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 665-666, Problem 11.3 #3 & #4
============================================================================*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// declaration section
class Complex {
	private:
	double realPart;       // declare realPart as a double variable
	double imaginaryPart;  // declare imaginaryPart as a double variable

  public:
	Complex(double real = 0.0, double imag = 0.0)    // inline constructor
  	  {realPart = real; imaginaryPart = imag;}
	void showComplexValues();                 // accessor prototype
	void assignNewValues(double real, double imag);  // inline mutator
	Complex operator+(const Complex&);  // prototype for the addition operator
	Complex operator-(const Complex&);  // prototype for the subtraction operator
	Complex operator*(const Complex&);  // prototype for the subtraction operator
	};   // end of class declaration
// implementation section
void Complex::showComplexValues()  // accessor
{
	char sign = '+';
	if (imaginaryPart < 0) sign = '-';
	cout << realPart << ' ' << sign << ' ' << abs(imaginaryPart) << 'i';
}

Complex Complex::operator+(const Complex& complex2) {
	Complex temp;
	temp.realPart = realPart + complex2.realPart;
	temp.imaginaryPart = imaginaryPart + complex2.imaginaryPart;
  return temp; }
Complex Complex::operator-(const Complex& complex2) {
	Complex temp;
	temp.realPart = realPart - complex2.realPart;
	temp.imaginaryPart = imaginaryPart - complex2.imaginaryPart;
  return temp; }
Complex Complex::operator*(const Complex& complex2) {
	//Algorithm: (a + bi) x (c + di) = (ab - bd) + (ad + bc)i.
	Complex temp,temp2;
	temp.realPart = (realPart *imaginaryPart)-(imaginaryPart*complex2.imaginaryPart);
	temp.imaginaryPart = (realPart * complex2.imaginaryPart)+(imaginaryPart*complex2.realPart);
  return temp; }
int main() {
	Complex a(2.3, 10.5), b(6.3, 19.2), c;  // declare three objects
    cout << "Complex number a is ";
    a.showComplexValues();
    cout << "\nComplex number b is ";
    b.showComplexValues();
    c = a + b;   // add two complex numbers
    cout << "\n\nThe sum of a and b: "; c.showComplexValues();
    c = a - b;
    cout << "\n\nThe subtraction of a and b: "; c.showComplexValues();
    c = a * b;
    cout << "\n\nThe multiplication of a and b: "; c.showComplexValues();

  return 0; }



