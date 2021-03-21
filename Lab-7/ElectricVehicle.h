#ifndef ElectricVehicle_h
#define ElectricVehicle_h
#include "Vehicle.h" 
#include <string>
using namespace std;

template <class T>
class ElectricVehicle : Vehicle<T> {
public:
	T currentCharge, maximumCharge, engineEfficiency;
	inline T calculateRange()
	{
		float km = (currentCharge * 100) / engineEfficiency;
		return km;
	}
	inline T percentEnergyRemaining()
	{
		float cm = (currentCharge / maximumCharge) * 100.0f;
		return cm;
	}
	inline void drive(T km)
	{
		currentCharge -= (km / 100) * engineEfficiency;
	}
	inline ElectricVehicle(T x, T y)
	{
		currentCharge = x;
		maximumCharge = x;
		engineEfficiency = y;

	}
	inline ~ElectricVehicle()
	{
		std::cout << "In Electric Destructor" << std::endl;
	}

};
#endif
