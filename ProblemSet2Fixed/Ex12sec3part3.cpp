//================================================================================
// Programmer	: Joseph Rondinelli
// File Name	: Ex12sec3part3.cpp
// Course		: Computational Problem Solving II - CPET
// Description	: Modified program by the book to demonstrate a static data member (NumRooms)
//				  being incremented everytime the constructor was called. Then its printed by the
//                the static member function dispFootage along with the total square footage of each
//				  Room object (RoomDimension).
// Other        : Textbook Problem: Bronson 4th Edition (2012), page 708, Problem 12.3 #3
//================================================================================

#include <iostream>
#include <cmath>
using namespace std;
// declaration section
class RoomDimension {
  private:
  //Data member declarations
    static double TotalSqFootage;  // static variable declaration
    static int NumRooms; // static variable declaration
    double length;
    double width;
  public:
  //Member function declarations
    static void dispFootage();  // static member function
    RoomDimension(double l = 0.0, double w = 0.0)  // inline constructor
    {
    	length = l;
    	width = w;
    	TotalSqFootage += l * w;
    	NumRooms++;

    }
    void resetDimension(double, double);
};
// static member definition
double RoomDimension::TotalSqFootage = 0.0;
int RoomDimension::NumRooms=0;
// implementation section
void RoomDimension::resetDimension(double len = 0.0, double wid = 0.0){
    	TotalSqFootage -= length * width;  // remove previous square footage
    	length = len;  width = wid;
    	TotalSqFootage += len * wid;  // add new square footage
    	dispFootage(); // static function can be called from inside function
}
  // static function definition
 void RoomDimension::dispFootage() {
	 cout << "The total square footage is now: " << TotalSqFootage << endl
		  << "Number of Rooms: " << NumRooms << endl;
 }
/*MAIN: Creates 2 rooms of select dimensions and displays their sq footage
        , then one room's dimension are changed and redisplayed. 
*/
  int main() {
  RoomDimension::dispFootage(); // static function call
  RoomDimension Kitchen(20.0, 15.0);
  RoomDimension::dispFootage(); // static function call
  RoomDimension Hall(25.0, 4.0);
  Hall.dispFootage();  // another means of calling the static function
  Hall.resetDimension(10, 5);
  return 0;
  }
