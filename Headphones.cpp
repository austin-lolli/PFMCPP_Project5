#include <iostream>
#include "Headphones.h"

Headphones::Headphones() {}

Headphones::~Headphones()
{
    std::cout << "Headphones disconnected! Volume last set at: " << this->volume << std::endl;
}

void Headphones::increaseVolume ( unsigned int vol )
{
    volume = vol;
    std::cout << "Volume set at: " << vol << std::endl;
}

unsigned int Headphones::maxThisVolume ( )
{
    this->volume = 10;
    return this->volume;
    
}

unsigned int Headphones::holdDecreaseVolume ( unsigned int vol, unsigned int target )
{
    if ( vol > target )
    {
        while( vol >= target )
        {
            vol -= 1;
            if( vol == target )
            {
                volume = vol;
                return vol;
            }
        }
    }

    volume = 0;
    return 0;
}

unsigned int Headphones::holdDecreaseThisVolume ( unsigned int target )
{
    if ( this->volume > target )
    {
        while( this->volume >= target )
        {
            this->volume -= 1;
            if( this->volume == target )
            {
                return this->volume;
            }
        }
    }

    this->volume = 0;
    return 0;
}

void Headphones::printStatus()
{ 
    std::cout << "Headphone Volume: " << this->volume << ". Power Switch: " << this->powerSwitch<< std::endl;
}

void Headphones::maxVol() 
{ 
    std::cout << "Increasing volume to: " << this->maxThisVolume() << std::endl; 
}
