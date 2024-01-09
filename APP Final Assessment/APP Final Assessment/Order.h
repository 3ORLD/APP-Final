#pragma once
#include "Item.h"
#include <vector>
#include <fstream>

class Order {
public:
    Order();
    ~Order();

    void addItem(const Item* item);
    void removeItem(size_t index);
    double calculateTotal() const;
    std::string toString() const;
    void printReceipt() const;

private:
    std::vector<const Item*> orderItems;
};

