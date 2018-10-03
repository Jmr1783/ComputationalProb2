/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : plate.cpp
 Course      : Computational Problem Solving II - CPET
 Description : Class name: Plate
 	 	 	   7 private data members:

 	 	 	   outerHeat: value of edge fixed heat sources
 	 	 	   innerHeat: value of initial temp of plate
 	 	 	   fixedHeat: value of fixed heat source
 	 	 	   x_pt: x-coordinate of fixed heat source
 	 	 	   y_pt: y-coordinate of fixed heat source
 	 	 	   temp_plate: array of values used to find the final temps for current_plate
 	 	 	   current_plate: A finalized version of temp values after x# of cycles of heat

			   6 member functions:

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


#include "plate.h"		// Contains the user-defined class Plate
#include <iostream>
#include <iomanip>
#include <math.h>

// implementation section

 Plate::Plate(){
	//Initialize private vars
	outerHeat = 20.0;
	innerHeat = 50.0;
	fixedHeat = 100.0;
	x_pt = 2; y_pt = 7;
	temp_plate[y_pt][x_pt] = fixedHeat;
	//Initialize finalized array
	for(int col = 9; col>=0; col--){
		for(int row = 0; row<10; row++){
			current_plate[row][col]=0;
		}
	}
	copyTempArray();
}

//copies elements from the current array to the temp
void Plate::copyCurrentArray(){
 	for(int col = 0; col<10; col++){
 		for(int row = 0; row<10; row++){
 			temp_plate[row][col] = current_plate[row][col];
 		}
 	}
}

//copies elements from the temp array to the current
void Plate::copyTempArray(){
	for(int col = 0; col<10; col++){
		for(int row = 0; row<10; row++){
			current_plate[row][col] = temp_plate[row][col];
		}
	}
}

//Goes through both arrays and compares elements the same location
//to find the change in value, if its greater than a particular value
// a flag is thrown and the function exits
bool Plate::temperatureAnalyser(){
	bool changedTemp_flag = true;

	for(int col = 1; col<9; col++){
		for(int row = 1; row<9; row++){
			if(fabs(current_plate[row][col] - temp_plate[row][col])>=0.01)
			{changedTemp_flag=false;break;}
		}
		if(changedTemp_flag==false){break;}
	}
	copyCurrentArray();
	return changedTemp_flag;
}

//Prints to console a 2D matrix with labels of a plate w/ 10 x 10 elements
void Plate::displayPlate(){
	int col=0,row=0;
	for(row = 9; row>=0; row--){
		cout<<row<<"  |  ";
		for(col = 0; col<=9; col++){

			if(!((row==y_pt)&&(col==x_pt))){cout << " " << fixed << setprecision(2) << current_plate[row][col] << " ";}
			else{cout << " " << fixed << setprecision(2) << current_plate[row][col];}

		}
		cout << endl;
	}
	cout<<"       -----  -----  -----  -----  -----  -----  -----  -----  -----  -----"<<endl
	    <<"         0      1      2      3      4      5      6      7      8      9";
	cout << endl;
}

//Goes through the temporary array and averages elements around each location in the 8 X 8 area
// the result is written to the current array. In order to know when the heat has been distributed properly
// a function checks for changes in temperature before and after to decide if the function
// should be run again to meet a certain  degree of precision.
bool Plate::distributeHeat(){
	for(int row = 8; row>=1; row--){
			for(int col = 1; col<9; col++){
				if(!((row==y_pt)&&(col==x_pt))){current_plate[row][col] = (temp_plate[row+1][col] + temp_plate[row-1][col]
									      + temp_plate[row][col+1] + temp_plate[row][col-1])/4.0;}
			}
		}
	return(temperatureAnalyser());
}

//An accessor function that returns the value of a cell in the current_plate array
double Plate::plateValue(int row,int col){
	return current_plate[row][col];
}



