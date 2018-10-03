/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : max_func.h
 Course      : Computational Problem Solving II - CPET
 Sources: George H. Zion for comments

 	    readMatrixFile() :  Purpose.: Prompts the user to enter a file
								  name and attempt to open the file
									  as input.  If the file opens, the
									  data (float) values will be read
									  into an 8x8 array.
							Input...: None
							Output..: Returns a boolean value. Returns
									  true if the file opens properly
									  (and the data is read). Returns
									  false if the file does not open.

		displayMatix() :    Purpose.: Displays the 8x8 array on the
									  console.
							Input...: None
							Output..: None

     	locateMaximas() :   Purpose.: Locates and displays the
									  coordinates of the maximas in
									  the 8x8 array.
							Input...: None
							Output..: None

		closeMatrixFile() : Purpose.: Closes the data file.
							Input...: None
							Output..: None
============================================================================*/
#ifndef SRC_MAX_FUNC_H_
#define SRC_MAX_FUNC_H_
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
// declaration section
class Matrix{
private:
	ifstream inFile;
	string filePath;
	double dataMemory[8][8];
	void initalizeMemory();
public:
		Matrix();
		bool readMatrixFile();
		void displayMatrix();
		void locateMaximas();
		void closeMatrixFile();
};
// end of section
#endif /* SRC_MAX_FUNC_H_ */
