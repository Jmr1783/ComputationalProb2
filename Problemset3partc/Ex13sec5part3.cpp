/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex13sec5part3.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Makes a link list of structs, 3 structs,  that stores the name of an individual and their phone number.
               The user is asked to input the values for each item of a struct and its added to the list. The list
               is then printed in the console. This is done with Insert() that creates new structs in the list,
               populate() that collects the name and number of an individual, and display() that prints the contents
               of each struct in the list to console.
 Other       : Textbook Problem: Bronson 4th Edition (2012), Chapter 13 sec 5 problem 3
============================================================================*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAXRECS = 3;   // maximum no. of records

struct TeleType
{
  string name;
  string phoneNo;
  TeleType *nextaddr;
};

void populate(TeleType *);   // function prototype needed by main()
void display(TeleType *);    // function prototype needed by main()
void insert(TeleType *);	// function prototype needed by main()
TeleType *current;

int main()
{
  int i;
  TeleType *list;

  // get a pointer to the first structure in the list
  list = new TeleType;
  current = list;

  // populate the current structure and create the remaining structures
  for(i = 0; i < MAXRECS - 1; i++)
  {
	insert(current);
  }

  populate(current);         // populate the last structure
  current->nextaddr = NULL;  // set the last address to a NULL address
  cout << "\nThe list consists of the following records:\n";
  display(list);   // display the structures

  return 0;
}

//Insert(): takes in the next address in the list
void insert(TeleType *nextaddr){
	//populates the current address
	populate(current);
	//then creates a new struct in the list
	//next address then points to the new address
	current->nextaddr = new TeleType;
	current = current->nextaddr; //current is then pointed to next address
}

// input a name and phone number
void populate(TeleType *record) // record is a pointer to a
{                              // structure of type TeleType
  cout << "Enter a name: ";
  getline(cin, record->name);
  cout << "Enter the phone number: ";
  getline(cin, record->phoneNo);

  return;
}

void display(TeleType *contents) // contents is a pointer to a
{                                      // structure of type TeleType
  while (contents != NULL)        // display till end of linked list
  {
    cout << '\n' << setiosflags(ios::left)
		 << setw(30) << contents->name
         << setw(20) << contents->phoneNo;
    contents = contents->nextaddr;
  }
  cout << endl;

  return;
}

