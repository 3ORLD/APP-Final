#include "MainCourse.h"

MainCourse::MainCourse(const std::string& name, double price, int calories)
    : Item(name, price, calories) {}

std::string MainCourse::toString() const {
    return Item::toString(); // MainCourse has no additional attributes
}

