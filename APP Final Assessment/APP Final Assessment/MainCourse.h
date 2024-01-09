#pragma once
#include "Item.h"

class MainCourse : public Item {
public:
    MainCourse(const std::string& name, double price, int calories);

    std::string toString() const override;
};

