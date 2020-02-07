/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

 Destructors
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
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
        std::cout << "Headphones disconnected! Volume last set at: " << volume << std::endl;
    }
    unsigned int volume { 3 };
    bool powerSwitch { true };

    void increaseVolume( unsigned int vol );
    unsigned int holdDecreaseVolume( unsigned int vol, unsigned int target );
};

Headphones::Headphones() {}

void Headphones::increaseVolume ( unsigned int vol )
{
    volume = vol;
    std::cout << "Volume set at: " << vol << std::endl;
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

/*
 copied UDT 2:
 */
struct GiftCard
{
    GiftCard();
    ~GiftCard()
    {
        if( cardBalance > 5.00 )
        {
            std::cout << "Oops! There goes $" << cardBalance << "!" << std::endl;
        }
        else if ( expirationDate < 20200204 )
        {
            std::cout << "I really wish I spent that sooner... " << std::endl;
        }
    }

    double cardNumber = 6155200244839177.0; //removed const from previous assignment to allow overwrite in constructor
    unsigned int expirationDate = 20221231; //yyyymmdd
    double cardBalance = 100.00;
    

    void makePurchase(double itemCost);
    double reloadCard(double addBalance);
    void recurringPurchase(double subscriptionCost, int subscriptionLength);
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

double GiftCard::reloadCard(double addBalance)
{
    cardBalance += addBalance;
    return cardBalance;
}

void GiftCard::recurringPurchase(double subscriptionCost, int subscriptionLength)
{
    for( int i = 0; i < subscriptionLength; ++i)
    {
        cardBalance -= subscriptionCost;
        std::cout << "Card billed $" << subscriptionCost << ". Your current balance is " << cardBalance << " and your subscription is active for " << subscriptionLength << " more months. " << std::endl;
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
        for( int i = 0; i < channel; ++i )
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
    void changeChannel( int changeTo );
    bool powerSwitch( bool power );
    void playThroughHeadphones( Headphones headphones );
    void channelUpOrDown( int changeTo );
};

Television::Television() {}

void Television::setVolume( int vol )
{
    volume = vol;

    std::cout << "Volume now set at: " << vol << std::endl;

}

void Television::changeChannel( int changeTo )
{
    int temp = channel; 

    channel = changeTo; 

    std::cout << "Channel changed from " << temp << " to " << changeTo << std::endl;
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
/*
 new UDT 4:
 */
struct AirPods
{
    AirPods();
    ~AirPods()
    {
        pods.increaseVolume(5);
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
        bigScreen.channelUpOrDown(3);
        std::cout << "Shutting down headphones, volume at: " <<turtleBeach.holdDecreaseVolume(0,0) << "." << std::endl;
    }
    
    Television bigScreen;
    Headphones turtleBeach;
};

HomeTheater::HomeTheater() {}

#include <iostream>
int main()
{
    AirPods airPods;
    HomeTheater digitalDream;
    digitalDream.bigScreen.channel = 7;
    

    std::cout << "good to go!" << std::endl;
}
