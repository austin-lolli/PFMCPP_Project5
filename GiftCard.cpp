
#include <iostream>
#include "GiftCard.h"

GiftCard::GiftCard() : cardNumber(2833730365431231.0), expirationDate(20230131), cardBalance(150.00)
{

}

GiftCard::~GiftCard()
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
