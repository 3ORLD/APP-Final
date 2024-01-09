#include "Order.h"
#include <iostream>
#include <iomanip>
#include "Appetiser.h"


Order::Order() {}

Order::~Order() {
    // Clean up allocated memory for order items
    for (const Item* item : orderItems) {
        delete item;
    }
}

void Order::addItem(const Item* item) {
    orderItems.push_back(item);
}

void Order::removeItem(size_t index) {
    if (index >= 1 && index <= orderItems.size()) {
        delete orderItems[index - 1];
        orderItems.erase(orderItems.begin() + index - 1);
    }
}

double Order::calculateTotal() const {
    double total = 0.0;
    int eligibleItems = 0;

    for (const Item* item : orderItems) {
        total += item->getPrice();
        if (dynamic_cast<const Appetiser*>(item) && dynamic_cast<const Appetiser*>(item)->isTwoForOne()) {
            eligibleItems++;
        }
    }

    // Apply 2-4-1 discount (free items)
    if (eligibleItems > 0) {
        int freeItems = eligibleItems / 2;
        double itemPrice = 0.0;

        for (const Item* item : orderItems) {
            if (dynamic_cast<const Appetiser*>(item) && dynamic_cast<const Appetiser*>(item)->isTwoForOne()) {
                if (freeItems > 0) {
                    itemPrice = item->getPrice();
                    total -= itemPrice;
                    freeItems--;
                }
            }
        }
    }

    return total;
}

std::string Order::toString() const {
    std::string result;
    for (size_t i = 0; i < orderItems.size(); ++i) {
        result += "(" + std::to_string(i + 1) + ") " + orderItems[i]->getName() +
            ": £" + std::to_string(orderItems[i]->getPrice()) + "\n";
    }
    return result;
}

void Order::printReceipt() const {
    std::ofstream receiptFile("receipt.txt");
    if (!receiptFile.is_open()) {
        std::cerr << "Error: Failed to create receipt file." << std::endl;
        return;
    }

    double total = calculateTotal();
    double savings = 0.0; // Assuming savings are calculated correctly

    receiptFile << "Receipt:\n";
    receiptFile << toString();
    receiptFile << "\nSavings: £" << std::fixed << std::setprecision(2) << savings << "\n";
    receiptFile << "Total: £" << std::fixed << std::setprecision(2) << total << "\n";

    receiptFile.close();
}
