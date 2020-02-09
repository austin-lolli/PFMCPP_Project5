/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <iostream>
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
};

Television::Television() {}

void Television::setVolume( int vol )
{
    volume = vol;

    std::cout << "Volume now set at: " << vol << std::endl;

}

void Television::setThisVolume( int volume )
{
    this->volume = volume;

    std::cout << "Volume now set at: " << this->volume << std::endl;

}

void Television::changeChannel( int changeTo )
{
    int temp = channel; 

    channel = changeTo; 

    std::cout << "Channel changed from " << temp << " to " << changeTo << std::endl;
}

void Television::changeThisChannel( int channel )
{
    int temp = this->channel; 

    this->channel = channel; 

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


void Television::thisChannelUpOrDown( int channel )
{
    if( channel == this->channel ) 
    {
        std::cout << "Already on channel " << this->channel << std::endl;
    }
    else if( channel > this->channel ) 
    {
        while( channel != this->channel )
        {
            ++this->channel; 
            std::cout << "Channel: " << this->channel << std::endl;
        }
    }
    else // changeTo < channel
    {
        int temp = this->channel - channel;
        for( int i = 0; i < temp; ++i )
        {
            --this->channel;
            std::cout << "Channel: " << this->channel << std::endl;
        }
    }
}
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
};

AirPods::AirPods() {}
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
};

HomeTheater::HomeTheater() {}

#include <iostream>
int main()
{
    Headphones beats;
    std::cout << "Beats Volume: " << beats.volume << " Power Switch: " << beats.powerSwitch << std::endl;
    beats.printStatus();
    beats.volume = 10;
    std::cout << "Increasing Beats Volume to: " << beats.volume << std::endl;
    beats.maxVol();

    GiftCard theater;
    theater.cardBalance = 25.00;
    theater.makeThisPurchase( 10.50 );
    std::cout << "Your remaining theater gift card balance is " << theater.cardBalance <<std::endl;
    theater.reloadThisCard( 25.00 );
    std::cout << "New theater gift card balance is " << theater.cardBalance << std::endl;

    Television crt;
    crt.changeThisChannel(3);
    std::cout << "CRT channel changed from 48 to " << crt.channel << std::endl;
    crt.setThisVolume(11);
    std::cout << "CRT volume now set at: " << crt.volume << std::endl;
    
    

    std::cout << "good to go!" << std::endl;
}
