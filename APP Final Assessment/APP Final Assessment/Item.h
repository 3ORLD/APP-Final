#pragma once
#include <string>

class Item {
public:
    Item(const std::string& name, double price, int calories);
    virtual ~Item(); // Virtual destructor for polymorphism

    std::string getName() const;
    double getPrice() const;
    int getCalories() const;

    virtual std::string toString() const;

private:
    std::string name;
    double price;
    int calories;
};



