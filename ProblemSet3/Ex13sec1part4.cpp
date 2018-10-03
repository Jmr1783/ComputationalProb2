/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex13sec1part4.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Makes a struct named stock which its contents are
  	  	  	   its name, earning approx and earnings ratio. The user is asked to input
  	  	  	   the values for each item of a stock and a loop then prints the contents of
  	  	  	   each in main.
 Other       : Textbook Problem: Bronson 4th Edition (2012), Chapter 13 sec 1 problem 4
============================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int size = 5;
	float price =0.0;
	//Creates a stock struct with 3 data types
	struct stock
	{
		string name;
		float earning;
		float ratio;
	};

	stock stocks_2017[size];

	//input data loop for structs
	cout << "Input <name> then <earning> then <ratio>"<< endl;
	for (int i=0; i<=(size-1); i++){
		cin >> stocks_2017[i].name >> stocks_2017[i].earning >> stocks_2017[i].ratio;
	cout << endl;
	}

	//print loop for data in structs
	for (int i=0; i<=(size-1); i++){
		price = stocks_2017[i].earning * stocks_2017[i].ratio;
		cout << stocks_2017[i].name <<',' << stocks_2017[i].earning <<','<< stocks_2017[i].ratio <<','<< price << endl;
	}

	return (0);
}
