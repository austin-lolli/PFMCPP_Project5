#pragma once

#include "LeakedObjectDetector.h"
#include "Television.h"
#include "Headphones.h"

struct HomeTheater
{
    HomeTheater();
    ~HomeTheater();
    
    Television bigScreen;
    Headphones turtleBeach;
    JUCE_LEAK_DETECTOR(HomeTheater)
};
