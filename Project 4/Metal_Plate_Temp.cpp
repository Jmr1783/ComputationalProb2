//========================================================================
// Name        : Metal_Plate_Temp.cpp
// Author      : Dr. George H. Zion
// Course	   : Computation Problem Solving II (CPET-321)
// Date		   : November 28, 2017  (Fall 20171)
// Description :
//
// Under steady-state conditions, the temperature at any point on the
// surface of a metal plate will be the average of the temperatures of
// all the points surrounding it.  This fact can be used in an iterative
// procedure to calculate the temperature distribution at all points on a
// plane.
//
// Figure #1 shows a square plate divided into 100 squares or nodes by a
// grid.  The temperature of the nodes form two-dimensional array.
//
// 		9 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
// 		8 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
// 		7 [ ][ ][X][ ][ ][ ][ ][ ][ ][ ]
// 		6 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
// 		5 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//		4 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//		3 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//		2 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//		1 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//		0 [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
//         0  1  2  3  4  5  6  7  8  9
//
//				Figure #1
//
// The temperature at all nodes at the edges of the plate are constrained
// to 20 degrees Celsius by a cooling system, and the temperature at the
// node (2,7) is fixed at 100 degrees Celsius by exposure to boiling water.
//
// A new estimate of the temperature T(R,C) at any node can be calculated
// from the average of the temperatures of all nodes surrounding it using
// the formula in Equation #1.
//
// T(R,C)new  = 1/4 ([ T(R+1, C) + T(R-1), C)  +  T(R, C+1)  +  T(R, C-1)]
//
//				Equation #1
//
// To determine the temperature distribution on the surface of a plate,
// initial assumptions must be made about the temperature at each node,
// then equation #1 is applied to calculate the new temperature at the
// node.  These updated temperatures are, in turn, used to calculate new
// temperature.  This process is repeated until all new temperatures at
// each node reach a steady-state.
//
// This program calculates the steady-state temperature distribution
// throughout the plate, making an initial assumption that all interior
// segments are at a temperature of 50 degrees Celsius (Remember that
// all outside segments are fixed at 20 degrees Celsius and the node (2,7)
// is fixed at 100 degrees Celsius).
//
// The program follows the following algorithm/pseudo-code:
//
//      1) Display the temperatures of the plane (initial conditions).
//	    2) Display an '*' on the screen.
//		3) Perform one interation of new temperature calculations
//		   for the plate.
//		4) If the change in any node temperature was greater-than 0.01
//		   degrees Celsius, return to step 2.
//		5) Display the temperatures of the plane (steady-state conditions)
//		6) Display the temperature at node (4,4).
//
// The program utilizes a user-defined library (plate.h & plate.cpp) that
// contains the class Plate.  This class contains the class constructor
// (i.e. Plate) and three member functions:
//
//		displayPlate()   :  Purpose.: Displays the current temperature of
//									  the plate in a grid format.
//							Input...: None
//							Output..: None
//
//		distributeHeat() :  Purpose.: Performs one iteration of new
//									  temperature calculations for the
//									  plate.
//							Input...: None
//							Output..: Returns a boolean value. Returns
//									  true if the temperature change in
//									  all the nodes is less-than 0.01
//									  degrees.  Otherwise, returns false.
//
//		plateValue()     :  Purpose.: Determine the current temperature
//									  of one node of the plate given the
//									  node's coordinates.
//							Input...: The coordinates (column, row) of a
//									  node.
//							Output..: Returns the temperature (double) of
//									  the node.
//
//========================================================================

//========================================================================
#include <iostream>		// Required for cin & cout
#include "plate.h"		// Contains the user-defined class Plate
using namespace std;

int main()
{

	// Instantiate an object (p1) of class Plate
	Plate p1;

	// Display the temperatures (initial values) of the plate
	p1.displayPlate();

	// Display one '*' to the screen and perform one iteration of new
	// temperature calculations. Continue this process until the change
	// in temperature for all nodes is less-then 0.01 degrees.
	do
	{
		cout << '*';
	}
	while(!p1.distributeHeat());

	// Display the temperatures (steady-state values) of the plate
	cout << endl;
	p1.displayPlate();

	// Display the temperature of node (4,4).  If correct, this value
	// will equal 29.43
	cout << "The Steady-State Temperature for Segment (4,4) is : ";
	cout << p1.plateValue(4,4) << endl;

    return 0;
}
//========================================================================
