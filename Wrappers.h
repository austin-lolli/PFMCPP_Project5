#pragma once

#include "LeakedObjectDetector.h"
#include "AirPods.h" FIXME remove this include.  you're not using anything in it.
#include "GiftCard.h" FIXME remove this include.  you're not using anything in it.
#include "Headphones.h" FIXME remove this include.  you're not using anything in it.
#include "HomeTheater.h" FIXME remove this include.  you're not using anything in it.
#include "Wrappers.h" FIXME remove this include.  you're not using anything in it.

FIXME forward declare your types being used as pointers.  Include in the cpp file since that's where you use them

struct HeadphonesWrapper
{
    HeadphonesWrapper( Headphones* ptr);
    ~HeadphonesWrapper();
    
    Headphones* pointerToHeadphones = nullptr;
};

struct GiftCardWrapper
{
    GiftCardWrapper( GiftCard* ptr);
    ~GiftCardWrapper();
    
    GiftCard* pointerToGiftCard = nullptr;
};

struct TelevisionWrapper
{
    TelevisionWrapper( Television* ptr);
    ~TelevisionWrapper();
    
    Television* pointerToTelevision = nullptr;
};

struct AirPodsWrapper
{
    AirPodsWrapper( AirPods* ptr);
    ~AirPodsWrapper();
    
    AirPods* pointerToAirPods = nullptr;
};

struct HomeTheaterWrapper
{
    HomeTheaterWrapper( HomeTheater* ptr);
    ~HomeTheaterWrapper();
    
    HomeTheater* pointerToHomeTheater = nullptr;
};
