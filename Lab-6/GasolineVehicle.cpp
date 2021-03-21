#include "GasolineVehicle.h" 
#include <iostream>
using namespace std;



float GasolineVehicle::calculateRange()
{
	float km = (currentGasoline * 100) / engineEfficiency;
	return km;
}

float GasolineVehicle::percentEnergyRemaining()
{
	float cm = (currentGasoline / maximumGasoline) * 100.0f;
	return cm;
}

void GasolineVehicle::drive(float km)
{
	currentGasoline -= (km / 100) * engineEfficiency;
}
GasolineVehicle::~GasolineVehicle()
{
	std::cout << "In Gasoline Destructor" << std::endl;
}
GasolineVehicle::GasolineVehicle(float a, float b)
{
	currentGasoline = a;
	maximumGasoline = a;
	engineEfficiency = b;

}
