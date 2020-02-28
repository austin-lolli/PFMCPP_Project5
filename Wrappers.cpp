#include "Wrappers.h"
#include "AirPods.h"
#include "GiftCard.h" 
#include "Headphones.h" 
#include "HomeTheater.h" 
#include "Television.h"

HeadphonesWrapper::HeadphonesWrapper( Headphones* ptr) : pointerToHeadphones( ptr ) { }

HeadphonesWrapper::~HeadphonesWrapper()
{
    delete pointerToHeadphones;
}

GiftCardWrapper::GiftCardWrapper( GiftCard* ptr) : pointerToGiftCard( ptr ) { }

GiftCardWrapper::~GiftCardWrapper()
{
    delete pointerToGiftCard;
}

TelevisionWrapper::TelevisionWrapper( Television* ptr) : pointerToTelevision( ptr ) { }

TelevisionWrapper::~TelevisionWrapper()
{
    delete pointerToTelevision;
}

AirPodsWrapper::AirPodsWrapper( AirPods* ptr) : pointerToAirPods( ptr ) { }

AirPodsWrapper::~AirPodsWrapper()
{
    delete pointerToAirPods;
}

HomeTheaterWrapper::HomeTheaterWrapper( HomeTheater* ptr) : pointerToHomeTheater( ptr ) { }
    
HomeTheaterWrapper::~HomeTheaterWrapper()
{
    delete pointerToHomeTheater;
}
