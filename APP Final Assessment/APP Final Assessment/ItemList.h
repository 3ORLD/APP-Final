#pragma once
#include "Item.h"
#include <vector>

class ItemList {
public:
    virtual ~ItemList(); // Virtual destructor for polymorphism

    virtual void addItem(Item* item) = 0;
    virtual std::string toString() const = 0;

    // You can add more member functions as needed for manipulation
};
