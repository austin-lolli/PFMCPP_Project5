
#include <iostream>
#include "Television.h"

Television::Television() {}

Television::~Television()
{   
    for( int i = 0; i < this->channel; ++i )
    {
        if( i % 2 == 0 )
        {
            std::cout << "Foo" << std::endl;
        }
        else
        {
            std::cout << "Bar" << std::endl;
        }
    }
}

void Television::setVolume( int vol )
{
    volume = vol;

    std::cout << "Volume now set at: " << vol << std::endl;

}

void Television::setThisVolume( int vol )
{
    this->volume = vol;

    std::cout << "Volume now set at: " << this->volume << std::endl;

}

void Television::changeChannel( int changeTo )
{
    int temp = channel; 

    channel = changeTo; 

    std::cout << "Channel changed from " << temp << " to " << changeTo << std::endl;
}

void Television::changeThisChannel( int c )
{
    int temp = this->channel; 

    this->channel = c; 

    std::cout << "Channel changed from " << temp << " to " << this->channel << std::endl;
}

bool Television::powerSwitch( bool power )
{
    if( power == true )
    {
        std::cout << "Powering on!" << std::endl;
        return true;
    }

    std::cout << "Shutting down." << std::endl;   
    return false;
}

void Television::playThroughHeadphones( Headphones headphones )
{
    volume = 0; 
    headphones.powerSwitch = true;
}

void Television::playThisThroughHeadphones( Headphones headphones )
{
    this->volume = 0; 
    headphones.powerSwitch = true;
}

void Television::channelUpOrDown( int changeTo )
{
    if( changeTo == channel ) 
    {
        std::cout << "Already on channel " << changeTo << std::endl;
    }
    else if( changeTo > channel ) 
    {
        while( channel != changeTo )
        {
            ++channel; 
            std::cout << "Channel: " << channel << std::endl;
        }
    }
    else // changeTo < channel
    {
        int temp = channel - changeTo;
        for( int i = 0; i < temp; ++i )
        {
            --channel;
            std::cout << "Channel: " << channel << std::endl;
        }
    }
}


void Television::thisChannelUpOrDown( int c )
{
    if( c == this->channel ) 
    {
        std::cout << "Already on channel " << this->channel << std::endl;
    }
    else if( c > this->channel ) 
    {
        while( c != this->channel )
        {
            ++this->channel; 
            std::cout << "Channel: " << this->channel << std::endl;
        }
    }
    else // changeTo < channel
    {
        int temp = this->channel - c;
        for( int i = 0; i < temp; ++i )
        {
            --this->channel;
            std::cout << "Channel: " << this->channel << std::endl;
        }
    }
}
