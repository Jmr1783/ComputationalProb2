/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex13sec3part4.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Makes a struct named employee which its contents are
  	  	  	   its name, employee number, hours of work and earnings rate. The user is asked to input
  	  	  	   the values for each item of a stock and a loop then prints the contents of
  	  	  	   each in main, with each employee the gross earnings and total work
  	  	  	   force gross pay are also printed in main.
 Other       : Textbook Problem: Bronson 4th Edition (2012), Chapter 13 sec 3 problem 4
============================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Global Variables
	float grossPay_total = 0.0;
	float grossPay = 0.0;
	int size = 6;

	//Creates a struct for a employee that holds data on that employeee
	struct employee
	{
		int num;
		string name;
		float rate;
		int hours;
	};

	employee employees_2017[size]; // create # stocks

	//input loop
	cout << "Input <name> then <earning> then <ratio>"<< endl;
	for (int i=0; i<=(size-1); i++){
		cin >> employees_2017[i].num >> employees_2017[i].name >> employees_2017[i].rate >> employees_2017[i].hours;
	cout << endl;
	}

	//print loop
	cout << "Formate: [Number],[name],[rate],[hours],[gross pay]"<< endl;
	for (int i=0; i<=(size-1); i++)
	{
		grossPay=employees_2017[i].rate * float(employees_2017[i].hours);
		cout << employees_2017[i].num <<','
			<< employees_2017[i].name <<','
			<< employees_2017[i].rate <<','
			<< employees_2017[i].hours <<','
			<< grossPay
		    << endl;
		grossPay_total+=grossPay;
	}
	cout<< "Gross Pay Total: "<< grossPay_total<<endl;

	return (0);
}
