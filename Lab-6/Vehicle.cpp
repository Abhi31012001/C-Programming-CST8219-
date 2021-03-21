#include "Vehicle.h"

Vehicle::Vehicle(int w, int d) {
}
Vehicle::Vehicle(int w) :Vehicle(w, 4) {

}
Vehicle::Vehicle() : Vehicle(4) {

}
Vehicle::~Vehicle() {
	cout << "In Vehicle Destructor" << endl;
}
