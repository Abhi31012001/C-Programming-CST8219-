
#ifndef Vehicle_h
#define Vehicle_h
#include<iostream>

using namespace std;

template <class T>
class Vehicle {
	T numWheels, numDoors;
public:
	inline Vehicle(T w, T d)
	{
		numWheels = w;
		numDoors = d;
	}
	inline Vehicle(T w) : Vehicle(w, 4) {}
	inline Vehicle() : Vehicle(4) {}

	inline ~Vehicle()
	{
		cout << "In Vehicle Destructor" << endl;
	}

	//virtual float calculateRange() = 0;
	//virtual float percentEnergyRemaining() = 0;
	//virtual void drive(float km) = 0;
};
#endif
