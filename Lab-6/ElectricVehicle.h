#ifndef ElectricVehicle_h
#define ElectricVehicle_h
#include "Vehicle.h" 
#include <string>
using namespace std;

class ElectricVehicle : virtual public Vehicle {
public:
	float currentCharge, maximumCharge, engineEfficiency;
	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
	ElectricVehicle(float x, float y);
	virtual ~ElectricVehicle();

};
#endif