/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : plate.h
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Plate) that has 7 private data members
 	 	 	   outerHeat: value of edge fixed heat sources
 	 	 	   innerHeat: value of initial temp of plate
 	 	 	   fixedHeat: value of fixed heat source
 	 	 	   x_pt: x-coordinate of fixed heat source
 	 	 	   y_pt: y-coordinate of fixed heat source
 	 	 	   temp_plate: array of values used to find the final temps for current_plate
 	 	 	   current_plate: A finalized version of temp values after x# of cycles of heat

			   And creates 6 function prototypes:

			   displayPlate()
			   	   >Displays a 2D Matrix of the current plate values

			   copyTempArray()
			   	   >copies elements from the temp array to the current array

			   copyCurrentArray();
               	   >copies elements from the current array to the temp array

               temperatureAnalyser();
               	   >Calculates the change of temp between each array and throws a
               	   flag if the change is too large

			   distributeHeat();
			   	   >Calculates the average of the cells and writes the result
			   	   to the current array

			   plateValue(int,int);
			   	   >Returns the value of a cell in the current array

============================================================================*/



#ifndef SRC_PLATE_H_
#define SRC_PLATE_H_

#include <iostream>
#include <iomanip>

using namespace std;



// declaration section
class Plate
{
		private:
			double outerHeat, innerHeat, fixedHeat;
			int x_pt, y_pt;
			double temp_plate[10][10] =
					    {{20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,50.0,20.0},
	                    {20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0,20.0}};
			double current_plate[10][10];
		// function prototypes
		public:
			Plate();
			void displayPlate();
			void copyTempArray();
			void copyCurrentArray();
            bool temperatureAnalyser();
			bool distributeHeat();
			double plateValue(int,int);

};
	// end of declaration section




#endif /* SRC_PLATE_H_ */
