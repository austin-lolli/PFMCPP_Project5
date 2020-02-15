/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */


#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct Headphones
{
    Headphones();
    ~Headphones() 
    {
        std::cout << "Headphones disconnected! Volume last set at: " << this->volume << std::endl;
    }
    unsigned int volume { 3 };
    bool powerSwitch { true };

    void increaseVolume( unsigned int vol );
    unsigned int maxThisVolume();
    unsigned int holdDecreaseVolume( unsigned int vol, unsigned int target );
    unsigned int holdDecreaseThisVolume ( unsigned int target );
    void printStatus(); 
    void maxVol() { std::cout << "Increasing volume to: " << this->maxThisVolume() << std::endl; }
    JUCE_LEAK_DETECTOR(Headphones)
};

Headphones::Headphones() {}

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

struct HeadphonesWrapper
{
    HeadphonesWrapper( Headphones* ptr) : pointerToHeadphones( ptr ) { }
    ~HeadphonesWrapper()
    {
        delete pointerToHeadphones;
    }
    
    Headphones* pointerToHeadphones = nullptr;
};
/*
 copied UDT 2:
 */
struct GiftCard
{
    GiftCard();
    ~GiftCard()
    {
        if( this->cardBalance > 5.00 )
        {
            std::cout << "Oops! There goes $" << this->cardBalance << "!" << std::endl;
        }
        else if ( this->expirationDate < 20200204 )
        {
            std::cout << "I really wish I spent that sooner... " << std::endl;
        }
    }

    double cardNumber = 6155200244839177.0; //removed const from previous assignment to allow overwrite in constructor
    unsigned int expirationDate = 20221231; //yyyymmdd
    double cardBalance = 100.00;
    

    void makePurchase(double itemCost);
    void makeThisPurchase(double itemCost);
    double reloadCard(double addBalance);
    double reloadThisCard(double addBalance);
    void recurringPurchase(double subscriptionCost, int subscriptionLength);
    void thisRecurringPurchase(double subscriptionCost, int subscriptionLength);
    JUCE_LEAK_DETECTOR(GiftCard)
};

GiftCard::GiftCard() : cardNumber(2833730365431231.0), expirationDate(20230131), cardBalance(150.00)
{

}
void GiftCard::makePurchase(double itemCost)
{
    if( expirationDate >= 20200131 )
    {
        cardBalance -= itemCost;

        std::cout << "Your remaining balance is: " << cardBalance << std::endl;
    }
    else
    {
        std::cout << "Card expired!" << std::endl;
    }
}

void GiftCard::makeThisPurchase(double itemCost)
{
    if( this->expirationDate >= 20200131 )
    {
        this->cardBalance -= itemCost;

        std::cout << "Your remaining gift card balance is: " << this->cardBalance << std::endl;
    }
    else
    {
        std::cout << "Card expired on: " << this->expirationDate << std::endl;
    }
}

double GiftCard::reloadCard(double addBalance)
{
    cardBalance += addBalance;
    return cardBalance;
}

double GiftCard::reloadThisCard(double addBalance)
{
    this->cardBalance += addBalance;
    std::cout << "New gift card balance is " << this->cardBalance << std::endl;
    return this->cardBalance;
}

void GiftCard::recurringPurchase(double subscriptionCost, int subscriptionLength)
{
    for( int i = 0; i < subscriptionLength; ++i)
    {
        cardBalance -= subscriptionCost;
        std::cout << "Card billed $" << subscriptionCost << ". Your current balance is " << cardBalance << " and your subscription is active for " << subscriptionLength << " more months. " << std::endl;
    }
}

void GiftCard::thisRecurringPurchase(double subscriptionCost, int subscriptionLength)
{
    for( int i = 0; i < subscriptionLength; ++i)
    {
        this->cardBalance -= subscriptionCost;
        std::cout << "Card billed $" << subscriptionCost << ". Your current balance is " << this->cardBalance << " and your subscription is active for " << subscriptionLength << " more months. " << std::endl;
    }
}

struct GiftCardWrapper
{
    GiftCardWrapper( GiftCard* ptr) : pointerToGiftCard( ptr ) { }
    ~GiftCardWrapper()
    {
        delete pointerToGiftCard;
    }
    
    GiftCard* pointerToGiftCard = nullptr;
};
/*
 copied UDT 3:
 */
struct Television
{   
    Television();
    ~Television()
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

Television::Television() {}

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

struct TelevisionWrapper
{
    TelevisionWrapper( Television* ptr) : pointerToTelevision( ptr ) { }
    ~TelevisionWrapper()
    {
        delete pointerToTelevision;
    }
    
    Television* pointerToTelevision = nullptr;
};
/*
 new UDT 4:
 */
struct AirPods
{
    AirPods();
    ~AirPods()
    {
        pods.maxThisVolume();
        std::cout << "Air Pods out of charge!" << std::endl;
    }

    Headphones pods;
    JUCE_LEAK_DETECTOR(AirPods)
};

AirPods::AirPods() {}

struct AirPodsWrapper
{
    AirPodsWrapper( AirPods* ptr) : pointerToAirPods( ptr ) { }
    ~AirPodsWrapper()
    {
        delete pointerToAirPods;
    }
    
    AirPods* pointerToAirPods = nullptr;
};
/*
 new UDT 5:
 */
struct HomeTheater
{
    HomeTheater();
    ~HomeTheater()
    {
        bigScreen.thisChannelUpOrDown(3);
        std::cout << "Shutting down headphones, volume at: " << turtleBeach.holdDecreaseThisVolume(0) << "." << std::endl;
    }
    
    Television bigScreen;
    Headphones turtleBeach;
    JUCE_LEAK_DETECTOR(HomeTheater)
};

HomeTheater::HomeTheater() {}

struct HomeTheaterWrapper
{
    HomeTheaterWrapper( HomeTheater* ptr) : pointerToHomeTheater( ptr ) { }
    ~HomeTheaterWrapper()
    {
        delete pointerToHomeTheater;
    }
    
    HomeTheater* pointerToHomeTheater = nullptr;
};

#include <iostream>
int main()
{
    HeadphonesWrapper beats( new Headphones() );
    std::cout << "Beats Volume: " << beats.pointerToHeadphones->volume << " Power Switch: " << beats.pointerToHeadphones->powerSwitch << std::endl;
    beats.pointerToHeadphones->printStatus();
    beats.pointerToHeadphones->volume = 10;
    std::cout << "Increasing Beats Volume to: " << beats.pointerToHeadphones->volume << std::endl;
    beats.pointerToHeadphones->maxVol();

    GiftCardWrapper theater( new GiftCard() );
    theater.pointerToGiftCard->cardBalance = 25.00;
    theater.pointerToGiftCard->makeThisPurchase( 10.50 );
    std::cout << "Your remaining theater gift card balance is " << theater.pointerToGiftCard->cardBalance <<std::endl;
    theater.pointerToGiftCard->reloadThisCard( 25.00 );
    std::cout << "New theater gift card balance is " << theater.pointerToGiftCard->cardBalance << std::endl;

    TelevisionWrapper crt( new Television() );
    crt.pointerToTelevision->changeThisChannel(3);
    std::cout << "CRT channel changed from 48 to " << crt.pointerToTelevision->channel << std::endl;
    crt.pointerToTelevision->setThisVolume(11);
    std::cout << "CRT volume now set at: " << crt.pointerToTelevision->volume << std::endl;
    
    

    std::cout << "good to go!" << std::endl;
}
