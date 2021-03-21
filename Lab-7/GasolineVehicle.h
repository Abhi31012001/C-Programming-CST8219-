#ifndef GasolineVehicle_h
#define GasolineVehicle_h
#include "Vehicle.h"
#include <string>
using namespace std;

template <class T>
class GasolineVehicle :  Vehicle<T> {
public:
	T currentGasoline, maximumGasoline, engineEfficiency;
	inline T calculateRange() 
		{
			T km = (currentGasoline * 100) / engineEfficiency;
			return km;
		}
	
	inline T percentEnergyRemaining()
	{
		T cm = (currentGasoline / maximumGasoline) * 100.0f;
		return cm;
	}
	inline void drive(T km) 
	{
		currentGasoline -= (km / 100) * engineEfficiency;
	}
	inline GasolineVehicle(T a, T b)
	{
		currentGasoline = a;
		maximumGasoline = a;
		engineEfficiency = b;

	}

	inline  ~GasolineVehicle()
	{
		std::cout << "In Gasoline Destructor" << std::endl;
	}


};
#endif