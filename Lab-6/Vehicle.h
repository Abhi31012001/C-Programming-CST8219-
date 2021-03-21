
#ifndef Vehicle_h
#define Vehicle_h
#include<iostream>
using namespace std;
class Vehicle {
	int numWheels, numDoors;
public:
	Vehicle(int w, int d);
	Vehicle(int w);
	Vehicle();

	virtual ~Vehicle();

	virtual float calculateRange() = 0;
	virtual float percentEnergyRemaining() = 0;
	virtual void drive(float km) = 0;
};
#endif
