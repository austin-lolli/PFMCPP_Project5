#include <iostream>
#include "HomeTheater.h"
/*#include "Headphones.h" FIXME remove this include.  you're not using anything in it.
#include "Television.h" FIXME remove this include.  you're not using anything in it.
*/
HomeTheater::HomeTheater() {}

HomeTheater::~HomeTheater() 
{
    bigScreen.thisChannelUpOrDown(3);
    std::cout << "Shutting down headphones, volume at: " << turtleBeach.holdDecreaseThisVolume(0) << "." << std::endl;
}
