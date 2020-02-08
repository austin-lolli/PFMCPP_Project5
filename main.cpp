/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}


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
    void increaseThisVolume( unsigned int volume );
    unsigned int holdDecreaseVolume( unsigned int vol, unsigned int target );
    unsigned int holdDecreaseThisVolume ( unsigned int target );
};

Headphones::Headphones() {}

void Headphones::increaseVolume ( unsigned int vol )
{
    volume = vol;
    std::cout << "Volume set at: " << vol << std::endl;
}

void Headphones::increaseThisVolume ( unsigned int volume )
{
    this->volume = volume;
    std::cout << "Volume set at: " << this->volume << std::endl;
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

        std::cout << "Your remaining balance is: " << this->cardBalance << std::endl;
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
    int temp = channel; 

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
        pods.increaseThisVolume(5);
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
	Example::main();
    AirPods airPods;
    HomeTheater digitalDream;
    digitalDream.bigScreen.channel = 7;
    

    std::cout << "good to go!" << std::endl;
}
