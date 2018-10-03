/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Project1.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named ComplexNumber with 3 data members
               (realPart), (imaginaryPart) and the symbol for polar or rectangular 
			   (present_Symbol). Then there are 7 memeber functions, one sets 
			   the values for each data memeber (setComplex), 
			   one takes in a char argument and converts the object to a different form
			   (converter), one shows the data inside each data memeber and prints them out
			   in two forms (polar or rectangular) (showData). Then there are 4 OverLoad operations
			   that add subtract multiply and divide the objects/ complex numbers accordingly.
Version      : 2.0.0
============================================================================*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
const double PI = 3.14159265359;
// declaration section
class ComplexNumber
{
	double realPart;
	double imaginaryPart;
	char present_Symbol;

public:
	ComplexNumber(char c = ' ',double r=0.0,double i=0.0)
	{present_Symbol=c;realPart=r;imaginaryPart=i;}
	void setComplex();
	void converter(char);
	void showData(){
		cout.precision(2);
		if(present_Symbol == 'r'){
			cout<< "R: "<<fixed<<realPart<<" + j"<<imaginaryPart<<"   ";
			converter('p');
			cout<< "P: "<<fixed<<realPart<<" < "<<imaginaryPart<<endl<<endl;}
		else{
			converter('r');
			cout<< "R: "<<fixed<<realPart<<" + j"<<imaginaryPart<<"   ";
			converter('p');
			cout<< "P: "<<fixed<<realPart<<" < "<<imaginaryPart<<endl<<endl;

		}
	}
	ComplexNumber operator+(const ComplexNumber&);
	ComplexNumber operator-(const ComplexNumber&);
	ComplexNumber operator*(const ComplexNumber&);
	ComplexNumber operator/(const ComplexNumber&);
};
// end of declaration section

// implementation section
void ComplexNumber::setComplex(){
	bool error;
	do{
	error=false;
	cin >> realPart >> imaginaryPart >> present_Symbol; cout<<endl<<endl;

	//Input error checking logic
	if(!((present_Symbol=='p')||(present_Symbol=='r'))){cout<< "Symbol not recognized"<<endl;error=true;}
	if(error){cout<<"Please revise you input..."<<endl<<endl;}
	//End of input error checking logic

	}while(error);
}

void ComplexNumber::converter(char convertTo){

	if((present_Symbol == 'p')&&(convertTo=='r')){
		double theta=(PI/180)*imaginaryPart,r=realPart;
		realPart=r*cos(theta);
	    imaginaryPart=r*sin(theta);
		present_Symbol='r';
	}//convert to rectangular

	else if((present_Symbol == 'r')&&(convertTo=='p')){
		double y=imaginaryPart,x=realPart;
		realPart=sqrt((x*x)+(y*y));
	    imaginaryPart=(atan2(y,x))*(180/PI);
		present_Symbol='p';
	}//convert to polar

}

//OverLoad operations
ComplexNumber ComplexNumber::operator+(const ComplexNumber& complex2) {
	ComplexNumber temp;
	temp.realPart = realPart + complex2.realPart;
	temp.imaginaryPart = imaginaryPart + complex2.imaginaryPart;
	temp.present_Symbol='r';
  return temp; }
ComplexNumber ComplexNumber::operator-(const ComplexNumber& complex2) {
	ComplexNumber temp;
	temp.realPart = realPart - complex2.realPart;
	temp.imaginaryPart = imaginaryPart - complex2.imaginaryPart;
	temp.present_Symbol='r';
  return temp; }
ComplexNumber ComplexNumber::operator*(const ComplexNumber& complex2) {
	ComplexNumber temp;
	temp.realPart = realPart * complex2.realPart;
	temp.imaginaryPart = imaginaryPart + complex2.imaginaryPart;
	temp.present_Symbol='p';
  return temp; }
ComplexNumber ComplexNumber::operator/(const ComplexNumber& complex2) {
	ComplexNumber temp;
	temp.realPart = realPart / complex2.realPart;
	temp.imaginaryPart = imaginaryPart - complex2.imaginaryPart;
	temp.present_Symbol='p';
  return temp; }
//OverLoad operations end

// End implementation section

int main()
{
	ComplexNumber var1,var2,result,temporaryObject;
	char choice=' '; bool loopBreakVariable=1;
	do{
		cout << "Select an operation:" << endl
		<< " e   : Enter ComplexNumber Numbers" << endl
		<< " c   : Calculation Options"<< endl
		<< " s   : Swap Currently Stored Values" << endl
		<< " m   : Move Answer to Stored Value" << endl
		<< "Q/q  : Quit" << endl << endl;
		cin >> choice;
		switch(choice){
			case'e':
				cout << "Enter Variable 1 in rectangular(r) or polar(p) (Ex: <num> <num> <p/r>): ";
				var1.setComplex();
				var1.showData();
				cout << "Enter Variable 2 in rectangular(r) or polar(p) (Ex: <num> <num> <p/r>): ";
				var2.setComplex();
				var2.showData();
				break;
			case 'c':
				cout<<"Select an operation: "<<endl
					<< " +   : Addition" << endl
					<< " -   : Subtraction" << endl
					<< " *   : Multiplication" << endl
					<< " /   : Division" << endl<<endl;
				cin >> choice;
				switch(choice){
				case'+':
					cout<<"Result: ";
					var1.converter('r');
					var2.converter('r');
					result=var1+var2;
					cout<<endl;
					result.showData();
					cout<<endl;
					break;
				case'-':
					cout<<"Result: ";
					var1.converter('r');
					var2.converter('r');
					result=var1-var2;
					cout<<endl;
					result.showData();
					cout<<endl;
					break;
				case'*':
					cout<<"Result: ";
					var1.converter('p');
					var2.converter('p');
				    result=var1*var2;
				    cout<<endl;
				    result.showData();
				    cout<<endl;
					break;
				case'/':
					cout<<"Result: ";
					var1.converter('p');
					var2.converter('p');
					result=var1/var2;
					cout<<endl;
					result.showData();
					cout<<endl;
					break;
				default:
					cout << "ERROR: Improper input"<<endl<<endl;
					break;
				}

				break;

			case's':
				temporaryObject=var1;
				var1=var2;
				var2=temporaryObject;
				cout <<"variable 1:"<< endl;
				var1.showData();
				cout <<"variable 2:"<< endl;
				var2.showData();
				cout<< endl <<"Swap Complete..." << endl<<endl;
			break;
			case'm':
				cout<<"1.) ANS => var2"<<endl<<"2.) ANS => var2"<<endl<<endl;
				cin>>choice;

				switch(choice){
					case '1':
						var1=result;
						cout<<"ANS => var1..." <<endl;
						cout <<"variable 1:"<< endl;
						var1.showData();
						cout << endl;
					break;
					case '2':
						var2=result;
						cout<<"ANS => var2..."<<endl;
						cout <<"variable 2:"<< endl;
						var1.showData();
						cout << endl;
					break;
					default:
						cout << "ERROR: Improper input"<<endl<<endl;
					break;
				}

			break;
			case('q'):
					loopBreakVariable = 0;
			break;
			case('Q'):
					loopBreakVariable = 0;
			break;
			default:
				cout << "ERROR: Improper input"<<endl<<endl;
			break;
		}
	}while(loopBreakVariable);

	return 0;
}



