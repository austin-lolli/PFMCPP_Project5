#pragma once

#include "LeakedObjectDetector.h"
#include "AirPods.h"
#include "GiftCard.h"
#include "Headphones.h"
#include "HomeTheater.h"
#include "Wrappers.h"

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
