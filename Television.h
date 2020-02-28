#pragma once

#include "LeakedObjectDetector.h"
#include "Headphones.h"

struct Television
{   
    Television();
    ~Television();
    
    bool isTvOn = false;
    int volume = 15;
    int channel = 48;
    
    void setVolume( int vol );
    void setThisVolume( int volume );
    void changeChannel( int changeTo );
    void changeThisChannel( int channel );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
    void playThisThroughHeadphones( Headphones headphones );
    void channelUpOrDown( int changeTo );
    void thisChannelUpOrDown( int changeTo );
    JUCE_LEAK_DETECTOR(Television)
};
