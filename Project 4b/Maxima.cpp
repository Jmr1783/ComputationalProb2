//========================================================================
// Name        : Maxima.cpp
// Author      : Dr. George H. Zion
// Course	   : Computation Problem Solving II (CPET-321)
// Date		   : December 5, 2017  (Fall 20171)
// Description :
//
// Maximas in a (n x n) matrix are defined as any location (coordinate)
// that has a value greater then all eight (8) surrounding locations.
//
// For example, in the 5 x 5 matrix shown below there are maximas at
// coordinates [1][2] (value 63.60) and [3][3] (value 73.50).
//
//			   C
//	           0       1       2       3       4
//	 R	 0   33.10,  11.10,  29.50,  45.00,  21.30,
//		 1	 24.10,  48.40,  43.10,  30.30,  34.40,
//		 2	 13.00,  63.60,  18.80,  37.20,  54.10,
//		 3	 26.40,  15.40,  22.90,  73.50,  28.00,
//		 4	  9.70,   3.40,  34.70,  41.10,  18.80,
//
// This program locates the coordinates of all maximas within an 8x8 matrix
// (array) and prints these locations to the console.
//
// The program follows the following algorithm/pseudo-code:
//
//      1) Prompt the user to enter the name of the data file.  If the
//		   file exist, read the contents of the file into an 8x8 data array.
//		   If the file does not exist, display an error message and
//         terminate the program.
//
//	    2) If the file opens properly, display the 8x8 data on the console.
//
//		3) Search the 8x8 array to locate and display the coordinates of
//		   all the maximas.
//
//		4) Finally, close the data file.
//
// The program utilizes a user-defined library (max_func.h & max_func.cpp)
// that contains the class Matrix.  This class contains the class
// constructor (i.e. Matrix) and four member functions:
//
//		readMatrixFile() :  Purpose.: Prompts the user to enter a file
//									  name and attempt to open the file
//									  as input.  If the file opens, the
//									  data (float) values will be read
//									  into than 8x8 array.
//							Input...: None
//							Output..: Returns a boolean value. Returns
//									  true if the file opens properly
//									  (and the data is read). Returns
//									  false if the file does not open.
//
//		displayMatix() :    Purpose.: Displays the 8x8 array on the
//									  console.
//							Input...: None
//							Output..: None
//
//		locateMaximas() :   Purpose.: Locates and displays the
//									  coordinates of the maximas in
//									  the 8x8 array.
//							Input...: None
//							Output..: None
//
//		closeMatrixFile() : Purpose.: Closes the data file.
//							Input...: None
//							Output..: None
//
//========================================================================

//========================================================================
#include "max_func.h"

int main ()
{
	Matrix M;

	if(M.readMatrixFile())
	{
		M.displayMatrix();
		M.locateMaximas();
		M.closeMatrixFile();
	}
    return 0;
}
//========================================================================
