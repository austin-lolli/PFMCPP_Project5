#pragma once

#include "LeakedObjectDetector.h"

struct GiftCard
{
    GiftCard();
    ~GiftCard();

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
