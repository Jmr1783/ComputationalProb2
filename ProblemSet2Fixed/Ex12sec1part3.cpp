//================================================================================
// Programmer	: Modified by Joseph Rondinelli
// File Name	: Ex12sec1part3.cpp
// Course		: Computational Problem Solving II - CPET
// Description	: Modified program by the book (program 12.1) to demonstrate the effects of making overload functions
//                used in output control not const. The result: Compiler rases no flags.
// Other        : Textbook Problem: Bronson 4th Edition (2012), page 692, Problem 12.1 #3
//================================================================================

#include <iostream>
#include <cmath>
using namespace std;
// declaration section
class Complex {
// prototype for the overloaded insertion operator
friend ostream& operator<<(ostream&,  Complex&);
  private:    double realPart;    double imaginaryPart;
  public:    Complex(double real = 0.0, double imag = 0.0)  // inline constructor
  { realPart = real; imaginaryPart = imag;}
};
// overloaded insertion operator function
ostream& operator<<(ostream& out,  Complex& num){
	char sign = '+';                      // set the
if (num.imaginaryPart < 0) sign = '-';  // correct sign

if (num.realPart == 0 && num.imaginaryPart == 0)    cout << 0;
else if (num.imaginaryPart == 0)
	cout << num.realPart;
else if (num.realPart == 0)
	cout << num.imaginaryPart << 'i';
else    cout << num.realPart << ' ' << sign << ' '<< abs(num.imaginaryPart) << 'i';
 return out;
}
// main program, creats a complex number and prints it
int main() {
	Complex complexOne(12.5,-18.2);
	cout << "The complex number just created is "  << complexOne << endl;
return 0;
}

