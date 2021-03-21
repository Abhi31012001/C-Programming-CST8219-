
#ifndef HybridVehicle_h
#define HybridVehicle_h
#include "GasolineVehicle.h" 
#include "ElectricVehicle.h" 
#include <string>
using namespace std;

class HybridVehicle :  public GasolineVehicle, public ElectricVehicle {
public:
	HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency);
	virtual ~HybridVehicle();
	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
};
#endif