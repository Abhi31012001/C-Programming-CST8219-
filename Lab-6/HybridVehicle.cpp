#include<iostream>
#include "HybridVehicle.h"

using namespace std;



float HybridVehicle::calculateRange() {
    float Km = (GasolineVehicle::calculateRange() + ElectricVehicle::calculateRange());
    return Km;
}

float HybridVehicle::percentEnergyRemaining()
{
    float cm = ((GasolineVehicle::percentEnergyRemaining() + ElectricVehicle::percentEnergyRemaining()) / 2);
    return cm;
}

void HybridVehicle::drive(float km)
{

    if (ElectricVehicle::calculateRange() < km) {
        float Out = ElectricVehicle::calculateRange();
       
        ElectricVehicle::drive(Out);

        float leftKm = km - Out;

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
HybridVehicle::~HybridVehicle()
{
    std::cout << "In Hybrid Destructor" << std::endl;
}
HybridVehicle::HybridVehicle(float maximumGasoline, float gasolineEfficiency, float maximumCharge, float electricEfficiency) :GasolineVehicle(maximumGasoline, gasolineEfficiency), ElectricVehicle(maximumCharge, electricEfficiency)
{

}
