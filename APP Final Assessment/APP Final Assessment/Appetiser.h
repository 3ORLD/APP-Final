#pragma once
#include "Item.h"

class Appetiser : public Item {
public:
    Appetiser(const std::string& name, double price, int calories, bool shareable, bool twoForOne);

    bool isShareable() const;
    bool isTwoForOne() const;

    std::string toString() const override;

private:
    bool shareable;
    bool twoForOne;
};

