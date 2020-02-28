#pragma once

#include "LeakedObjectDetector.h"

struct Headphones
{
    unsigned int volume { 3 };
    bool powerSwitch { true };

    Headphones();
    ~Headphones();

    void increaseVolume( unsigned int vol );
    unsigned int maxThisVolume();
    unsigned int holdDecreaseVolume( unsigned int vol, unsigned int target );
    unsigned int holdDecreaseThisVolume ( unsigned int target );
    void printStatus(); 
    void maxVol();
    JUCE_LEAK_DETECTOR(Headphones)
};
