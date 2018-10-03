//================================================================================
// Programmer	: Modified by Joseph Rondinelli
// File Name	: Ex12sec1part4.cpp
// Course		: Computational Problem Solving II - CPET
// Description	: Modified program by the book (program 12.2) to demonstrate the effects of making overload functions
//                used in input control const. The result: Compiler flags this as an error.
// Other        : Textbook Problem: Bronson 4th Edition (2012), page 692, Problem 12.1 #4
//================================================================================
#include <iostream>
#include <cmath>
using namespace std;
// declaration section
class Complex {
// prototype for the overloaded insertion operator
friend ostream& operator<<(ostream&, const Complex&);
friend istream& operator>>(istream&, const Complex&);
   double realPart;
   double imaginaryPart;

public:    Complex(double real = 0.0, double imag = 0.0)  // inline constructor
  { realPart = real; imaginaryPart = imag;}
};
// overloaded insertion operator function
ostream& operator<<(ostream& out, const Complex& num){
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
// overloaded extraction operator function
istream& operator>>(istream& in, const Complex& num) {
	string temp;  double value;
	int plusLocation, minusLocation, i_Location;
  in >> value;        // accept the first number
  getline(cin,temp);  // input remaining characters entered, if any
  plusLocation = temp.find('+');   // find whether a + was entered
  minusLocation = temp.find('-');  // find whether a - was entered
  i_Location = temp.find('i');     // find whether an i was entered
  if (plusLocation >= 0 || minusLocation >= 0) // if there's a + or - sign
  {                                            // after the first number
	  num.realPart = value;
	  if (plusLocation >= 0)
		  temp.replace(plusLocation,1," ");
	  if (minusLocation >= 0)
		  temp.replace(minusLocation,1," ");
	  if (i_Location >= 0)
		  temp.replace(i_Location,1," ");
  }
// Convert to a C-string and then to a double-precision value
  //   and assign the value to the object's imaginary part
  num.imaginaryPart = atof(temp.c_str());   // imaginary part
  // If a - sign is present, negate the imaginary part
  if (minusLocation >= 0) num.imaginaryPart = -num.imaginaryPart;

  else if (i_Location >= 0)  // only an i follows the first value
	  {    num.realPart = 0.0; num.imaginaryPart = value;  }
  else  // no legitimate characters follow the first number
	  {    num.realPart = value;    num.imaginaryPart = 0.0;  }
  return in;
}

int main() {
	Complex complexOne(12.5,-18.2);
	cin  >> complexOne;   // accept the complex number, using cin
	cout << "The complex number just created is"  << complexOne << endl;
return 0;
}
