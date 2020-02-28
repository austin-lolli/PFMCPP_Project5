#pragma once

#include "LeakedObjectDetector.h"
#include "Headphones.h"

struct AirPods
{
    AirPods();
    ~AirPods();

    Headphones pods;
    JUCE_LEAK_DETECTOR(AirPods)
};
