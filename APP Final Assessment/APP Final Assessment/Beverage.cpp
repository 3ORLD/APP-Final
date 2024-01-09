#include "Beverage.h"
#include <sstream>

Beverage::Beverage(const std::string& name, double price, int calories, double abv, int volume)
    : Item(name, price, calories), abv(abv), volume(volume) {}

double Beverage::getABV() const {
    return abv;
}

int Beverage::getVolume() const {
    return volume;
}

std::string Beverage::toString() const {
    std::stringstream ss;
    ss << Item::toString();
    ss << "ABV: " << abv << "%\n";
    ss << "Volume: " << volume << " ml\n";
    return ss.str();
}
