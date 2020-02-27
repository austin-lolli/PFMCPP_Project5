#include <iostream>
#include "HomeTheater.h"
#include "Headphones.h"
#include "Television.h"

HomeTheater::HomeTheater() {}

HomeTheater::~HomeTheater() 
{
    bigScreen.thisChannelUpOrDown(3);
    std::cout << "Shutting down headphones, volume at: " << turtleBeach.holdDecreaseThisVolume(0) << "." << std::endl;
}
