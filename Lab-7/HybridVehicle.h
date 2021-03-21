
#ifndef HybridVehicle_h
#define HybridVehicle_h
#include "GasolineVehicle.h" 
#include "ElectricVehicle.h" 
#include <string>
using namespace std;
template <class T>
class HybridVehicle :  public GasolineVehicle<T>, public ElectricVehicle<T> {
public:
	inline HybridVehicle(T maximumGasoline, T gasolineEfficiency, T maximumCharge, T electricEfficiency) : GasolineVehicle<T>(maximumGasoline, gasolineEfficiency), ElectricVehicle<T>(maximumCharge, electricEfficiency) {}
	inline ~HybridVehicle()
	{
		std::cout << "In Hybrid Destructor" << std::endl;
	}
	inline T calculateRange()
    {
        T Km = (GasolineVehicle::calculateRange() + ElectricVehicle::calculateRange());
        return Km;
    }
	inline T percentEnergyRemaining()
    {
        T cm = ((GasolineVehicle::percentEnergyRemaining() + ElectricVehicle::percentEnergyRemaining()) / 2);
        return cm;
    }
	inline void  drive(T km)
    {

        if (ElectricVehicle::calculateRange() < km) {
            T Out = ElectricVehicle::calculateRange();

            ElectricVehicle::drive(Out);

            T leftKm = km - Out;

            if (GasolineVehicle::calculateRange() < leftKm) {

                GasolineVehicle::drive(GasolineVehicle::calculateRange());

                std::cout << "Your car is out of energy" << std::endl;
            }
            else {

                GasolineVehicle::drive(leftKm);

            }
        }
        else {
            ElectricVehicle::drive(km);
        }
    }
};
#endif