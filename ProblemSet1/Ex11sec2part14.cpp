/*============================================================================
 Programmer  : Joseph M. Rondinelli
 File Name   : Ex11sec1part5-14.dox
 Course      : Computational Problem Solving II - CPET
 Description : Constructs a class named (Student) that has 2 double data members (ID)
			   and (GPA). The class has two member functions that set
			   the value for the Rectangle (setData), show the Data (showData)
			   in ID and Gpa.
 Other       : Textbook Problem: Bronson 4th Edition (2012), page 644, Problem 11.2 #14
============================================================================*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// declaration section
class Food
{
	private:
		string type;
		int quantity;
		string name;
		double cost;

	public:
		Food(string="basic",string="null",int=0,double=0.0);
		void addFood();
		void modifyFood(string t,string n,int q,double c);
		void deleteFood();
		void showFood();
};
// end of declaration section

// implementation section
Food::Food(string t,string n,int q,double c)
{
	type=t;
	name=n;
	quantity=q;
	cost=c;
}

void Food::addFood(){

	cout << "Enter Food Type (basic/prep): ";
	cin >> type; cout<<endl;

	if (type == "basic"){
		cout << "Please specify your food item: ";
		cin >> name;
	}
	cin >> quantity;
	cin >> cost;
	showFood();
}

void Food::modifyFood(string t,string n,int q,double c)
{
	type=t;
	name=n;
	quantity=q;
	cost=c;
	showFood();
}

void Food::showFood(){

	cout << "Food Type: " << type << endl;
	if (type == "basic"){
		cout << name << endl;
	}
	cout << "Quantity: " << quantity << endl;
	cout << "Cost: " << cost << endl;
}


// end implementation section

//Main includes an interface for manipulating food items in an array
int main()
{

	Food food[100];

	int answer=0,id=0,newCost=0,newQuantity=0;
	string newName="null",newType="null";

	do{
		answer=0;
		cout << "What would you like to do?\n"
		<< "1.) Add a food item\n"
		<< "2.) Modify a food item\n"
		<< "3.) Delete a food item\n"
		<< "4.) Exit this menu\n";
		cin >> answer;

		switch(answer){
			case 1://Add food item
				cout << "Enter the items # to be added: ";
				cin >> id; cout<<endl;
			    food[id].addFood();
				break;
			case 2: //Modify Food Item
				cout << "Enter the items # to be modified: ";
				cin >> id; cout<<endl;
				cout << "Enter the item's new type: ";
				cin >> newType; cout<<endl;
				if (newType == "basic"){
				cout << "Enter the item's new name: ";
				cin >> newName; cout<<endl;
				}
				cout << "Enter the item's new quantity: ";
				cin >> newQuantity; cout<<endl;
				cout << "Enter the item's new cost: ";
				cin >> newCost; cout<<endl;
				food[id].modifyFood(newType,newName,newQuantity,newCost);

				break;
			case 3: //Delete Item
				cout << "Enter the items # to be deleted: ";
				cin >> id; cout<<endl;
				food[id].modifyFood("null","null",0,0.0);
				break;
			default:
				cout << "Exiting Menu..." << endl;
				break;
		}

	}while(answer !=4);

	system("Pause");
	return 0;
}

