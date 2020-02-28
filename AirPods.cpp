#include <iostream>
#include "AirPods.h"

AirPods::AirPods() {}

AirPods::~AirPods()
{
    pods.maxThisVolume();
    std::cout << "Air Pods out of charge!" << std::endl;
}
