#include<iostream>
#include<string>

using namespace std;
#pragma once
class Vehicle {
public:
	int numWheels;
	int numDoors;
	
	friend ostream& operator<<(ostream& out, const Vehicle& v);

	
	Vehicle();
	Vehicle(int w) ;

	Vehicle(int w, int d);

	~Vehicle();
	void setnumWidth(int d);
	void setnumDoor(int w);
	int getnumWidth(void) const;
	int getnumDoor(void) const;
	Vehicle(Vehicle& copy);
	Vehicle(Vehicle*);
	//Vehicle(Vehicle* copy) : Vehicle(& copy);
	void printVehicle(void);
	Vehicle operator=(const Vehicle& other) {

		return Vehicle(numWheels = numDoors);
	}
	Vehicle operator==(const Vehicle&) {
		if (numWheels == numDoors) {
			return true;
		}
	}
	Vehicle operator!=(const Vehicle&) {
		if (numWheels != numDoors) {
			return  false;
		}
	}
	Vehicle operator++(int n) {
		Vehicle copy(this);
		setnumWidth(numWheels + numDoors);
		return copy;
	}
	Vehicle operator++() {
		
		numWheels += numDoors;
		return Vehicle(this);
	}
	Vehicle operator--(int n) {
		Vehicle copy(this);
		setnumWidth(numWheels + numDoors);
		return copy;
	}
	Vehicle operator--() {

		numWheels += numDoors;
		return Vehicle(this);
	}

};
