

#include<iostream>
#include "Vehicle.h"
#include<ostream>

using namespace std;

ostream& operator<<(ostream& out, const Vehicle& v) {
	out << "The Value of numWidth: " << v.getnumWidth() << "\nThe Value of numDoor: " << v.getnumDoor();
	return out;
}
Vehicle::Vehicle() : Vehicle(4) {
	cout << "In constructor with 0 parameters" << endl;
}
Vehicle::Vehicle(int w) : Vehicle(4, w) {
	cout << "In constructor with 1 parameters, wheels = " << w << endl;
}

Vehicle::Vehicle(int w, int d) {
	numWheels = w;
	numDoors = d;
	cout << "In constructor with 2 parameters" << endl;
}

Vehicle::~Vehicle() {
	cout << "In destructor" << endl;
}
void Vehicle::setnumWidth(int w) {
	numWheels = w;
}
void Vehicle::setnumDoor(int d) {
	numDoors = d;
}

int Vehicle::getnumWidth() const{
	return numWheels;
}
int Vehicle::getnumDoor() const{
	return numDoors;
}
Vehicle::Vehicle(Vehicle& copy):Vehicle(& copy) {
	
	//setnumWidth(copy.getnumWidth());
	//setnumDoor(copy.getnumDoor());
}		
Vehicle::Vehicle(Vehicle* copy){

	setnumWidth(copy->getnumWidth());
	setnumDoor(copy->getnumDoor());
}


void Vehicle::printVehicle(void) {
	cout << "The Value of numWidth: " << getnumWidth() << "\nThe Value of numDoor: " << getnumDoor() << endl;

}