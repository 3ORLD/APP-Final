#include "Appetiser.h"
#include <sstream>

Appetiser::Appetiser(const std::string& name, double price, int calories, bool shareable, bool twoForOne)
    : Item(name, price, calories), shareable(shareable), twoForOne(twoForOne) {}

bool Appetiser::isShareable() const {
    return shareable;
}

bool Appetiser::isTwoForOne() const {
    return twoForOne;
}

std::string Appetiser::toString() const {
    std::stringstream ss;
    ss << Item::toString();
    ss << "Shareable: " << (shareable ? "Yes" : "No") << "\n";
    ss << "2-4-1: " << (twoForOne ? "Yes" : "No") << "\n";
    return ss.str();
}

