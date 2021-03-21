
#include<iostream>
using namespace std;


class Vehicle {
private:
	int numWheels;
	int numDoors;
public:
	Vehicle() : Vehicle(4) {
		cout << "In constructor with 0 parameters" << endl;
	}
	Vehicle(int w) : Vehicle(4, w) {
		cout << "In constructor with 1 parameters, wheels = " << w << endl;
	}

	Vehicle(int w, int d) {
		numWheels = w;
		numDoors = d;
		cout << "In constructor with 2 parameters"  << endl;
	}

	~Vehicle() {
		cout << "In destructor" << endl;
	}
};
int main(int argc, char** argv)
{
	int d = 0, w = 0;
	char choice;
	Vehicle veh1;
	cout << "\nVechile(1) takes " << sizeof(veh1) << "\n " << endl;
	Vehicle veh2(4);
	cout << "\nVechile(2) takes " << sizeof(veh2) <<  "\n " << endl;
	Vehicle veh3(4, 2);
	cout << "\nVechile(3) takes " << sizeof(veh3) << "\n " << endl;
	cout << "\nI made a vehicle" << endl;
	do {
		cout << "\nSelect your choice  (q for quit):" << endl;
		cin >> choice;
		Vehicle* pVehicle = 0;
		if (choice == 'q' || choice == 'Q') {

			return 0;
		}
		else {
			do {

				delete pVehicle;
				cout << "\nEnter width of vehicle: " << endl;
				cin >> d;
				cout << "\nEnter height of vehicle: " << endl;
				cin >> w;
				//cout << "I made a vehicle" << endl;

			} while (d < 0 || w < 0);
			pVehicle = new Vehicle(w, d);
		}
	} while (choice != 'q' || choice != 'Q');

	}