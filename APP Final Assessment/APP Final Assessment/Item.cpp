#include "Item.h"
#include <sstream>

Item::Item(const std::string& name, double price, int calories)
    : name(name), price(price), calories(calories) {}

Item::~Item() {}

std::string Item::getName() const {
    return name;
}

double Item::getPrice() const {
    return price;
}

int Item::getCalories() const {
    return calories;
}

std::string Item::toString() const {
    std::stringstream ss;
    ss << "Name: " << name << "\n";
    ss << "Price: $" << price << "\n";
    ss << "Calories: " << calories << " kcal\n";
    return ss.str();
}
