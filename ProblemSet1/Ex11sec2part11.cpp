/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part5-14.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Student) that has 2 double data members (ID)
			   and (GPA). The class has two member functions that set
			   the value for the Rectangle (setData), show the Data (showData)
			   in ID and Gpa.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 644, Problem 11.2 #11
============================================================================*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// declaration section
class Student
{
	private:
		double ID, GPA;
	public:
		Student (int = 111111 , double = 0.0);
		void setData();
		void showData();


};
// end of declaration section

// implementation section
Student::Student(int id, double gpa)
{
	ID = id;
	GPA = gpa;
}

void Student::setData()
{
	cout << "ID: ";
	cin >> ID;
	cout << "GPA: ";
	cin >> GPA;
}

void Student::showData()
{
	cout << "ID = " << ID << "\nGPA = "<< GPA << endl;
}


// end implementation section

/*MAIN:
 * In main a Student data type was filled with values with
 * and was displayed with showdata().
 */
int main()
{

	Student st1(123456,67.98),st2(789101,97.89);

	st1.showData();
	st2.showData();

	return 0;
}
