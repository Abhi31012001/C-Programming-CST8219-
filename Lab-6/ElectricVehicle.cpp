#include "ElectricVehicle.h" 
#include <iostream>
using namespace std;

float ElectricVehicle::calculateRange()
{
	float km = (currentCharge * 100) / engineEfficiency;
	return km;
}

float ElectricVehicle::percentEnergyRemaining()
{
	float cm = (currentCharge / maximumCharge) * 100.0f;
	return cm;
}

void ElectricVehicle::drive(float km)
{
	currentCharge -= (km / 100) * engineEfficiency;
}

ElectricVehicle::~ElectricVehicle()
{
	std::cout << "In Electric Destructor" << std::endl;
}

ElectricVehicle::ElectricVehicle(float x, float y)
{
	currentCharge = x;
	maximumCharge = x;
	engineEfficiency = y;

}
