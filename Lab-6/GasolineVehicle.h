#ifndef GasolineVehicle_h
#define GasolineVehicle_h
#include "Vehicle.h"
#include <string>
using namespace std;

class GasolineVehicle : virtual public Vehicle {
public:
	float currentGasoline, maximumGasoline, engineEfficiency;
	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
	GasolineVehicle(float a, float b);
	virtual ~GasolineVehicle();

};
#endif