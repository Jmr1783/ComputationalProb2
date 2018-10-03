/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : max_func.cpp
 Course      : Computational Problem Solving II - CPET
 Description : This file includes the source code for the max_func.h, explanations of members below
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
#include "max_func.h"
#include <fstream>
//constructor function
Matrix::Matrix(){
	filePath = "   ";
	initalizeMemory();
}
// Member Function: Opens File stream and reads from file
bool Matrix::readMatrixFile(){
	bool fileFound_flag=0;
	cout << "File name: " << endl; cin >> filePath;
	inFile.open(filePath);
	if(inFile.fail())
		cout << "\nFile Doesn't Exist...";
	else{
		fileFound_flag=1;
		cout << "\nFile found..."<<endl;
	}
	//fill the array with data from file
	for(int j=0;j<8;j++){
		for(int k=0;k<8;k++){
			inFile >> dataMemory[j][k];
		}
	}
	return fileFound_flag;
}

// Member Function: Fills array w/ 0's
void Matrix::initalizeMemory(){
	for(int j=0;j<8;j++){
		for(int k=0;k<8;k++){
			dataMemory[j][k]=0;
		}
	}
}

// Member Function: Prints Array
void Matrix::displayMatrix(){
	for(int j=0;j<8;j++){
		for(int k=0;k<8;k++){
			if(dataMemory[j][k]<10){cout<<' ';}
			cout<<fixed<<setprecision(2)<<dataMemory[j][k]<<' ';
		}
	cout<<endl;
	}
}

// Member Function: Finds Maxima's
void Matrix::locateMaximas(){
	for(int j=1;j<7;j++){ // move through
		for(int k=1;k<7;k++){
			bool notMaximume_flag = false;
			for(int y=-1;y<2;y++){ //move along y of 3x3 scan section
				for(int x=-1;x<2;x++){ //move along x of 3x3 scan section
					if(!((y==0) && (x==0))){ // at compare pt
						if(dataMemory[j+x][k+y] > dataMemory[j][k]){ //is this pt larger than compare pt
							notMaximume_flag=true; break;
						}
					}
				}//end x loop
				if(notMaximume_flag) break;
			}//end y loop
			if(notMaximume_flag==false)
				cout<<"Maxima @ ("<<k<<','<<j<<')'<<dataMemory[j][k]<<endl;
		}
	}
}

//Member Function: Closes File Stream
void Matrix::closeMatrixFile(){inFile.close();}
