/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex13sec2part4.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Makes a struct named date that stores the day month and year. The user is asked to input
  	  	  	   the values for each item of a date.The dates are then sent into a function called
  	  	  	   larger() and the 2 dates are compared to see who is larger. Both dates and the answer is then printed out.
 Other       : Textbook Problem: Bronson 4th Edition (2012), Chapter 13 sec 2 problem 4
============================================================================*/
#include <iostream>
#include <iomanip>
using namespace std;

//Creates a struct for a date that holds data on that date
struct date
{
	int day;
	int month;
	int year;
}date1, date2;

date tmp{0,0,0};

//takes in 2 date structs and compares the data to see who has the largest date
date larger(date date1, date date2){
	date larger_date = tmp;
	if(date1.year==date2.year){
		if(date1.month==date2.month){
			if(date1.day==date2.day){
			 cout << "Identical" << endl;
			}
			else if(date1.day>date2.day){larger_date=date1;}
			else{larger_date=date2;}
		}
		else if(date1.month>date2.month){larger_date=date1;}
		else{larger_date=date2;}
	}
	else if(date1.year>date2.year){larger_date=date1;}
	else{larger_date=date2;}

	return larger_date;
}

int main()
{
	//input phase
	cout<<"Format: <month> <day> <year>"<<endl;
	cout<<"input Date1: "<<endl;
	cin>> date1.month >> date1.day >> date1.year;
	cout<<"input Date2: "<<endl;
	cin>> date2.month >> date2.day >> date2.year;

	//send in 2 dates to be compared
	tmp=larger(date1,date2);

	//output phase
	cout << "Date1: " << date1.month << "/" << date1.day << "/" << date1.year << endl;
	cout << "Date2: " << date2.month << "/" << date2.day << "/" << date2.year << endl;
	cout << "Larger Date: " << tmp.month << "/" << tmp.day << "/" << tmp.year << endl;
	return (0);
}


