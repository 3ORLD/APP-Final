#pragma once
#include "Item.h"

class Beverage : public Item {
public:
    Beverage(const std::string& name, double price, int calories, double abv, int volume);

    double getABV() const;
    int getVolume() const;

    std::string toString() const override;

private:
    double abv; // Alcohol by volume
    int volume; // Volume in milliliters
};


