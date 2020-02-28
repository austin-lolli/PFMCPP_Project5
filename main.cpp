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
#include "Wrappers.h"
#include "AirPods.h"
#include "GiftCard.h"
#include "Headphones.h"
#include "HomeTheater.h"
#include "Television.h"


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
