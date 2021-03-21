#pragma once
cmake_minimum_required(VERSION 2.8.9)

project (hello)

add_executable(hello "week.cpp"  "Vehicle.cpp" "Vehicle.h"     "ElectricVehicle.cpp" "ElectricVehicle.h" "GasolineVehicle.cpp" "GasolineVehicle.h" "HybridVehicle.cpp" "HybridVehicle.h")