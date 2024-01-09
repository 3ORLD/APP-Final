#include "Menu.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Appetiser.h"
#include "Beverage.h"
#include "MainCourse.h"

Menu::Menu(const std::string& filePath) {
    // Open the CSV file and read menu items
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Failed to open menu file: " << filePath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        char itemType = line[0];
        std::string itemName, shareable, twoForOne, abv, volumeStr;
        double price;
        int calories, volume;
        bool isShareable = false, isTwoForOne = false;
        double itemABV = 0.0;

        std::istringstream ss(line.substr(2));
        ss >> itemName >> price >> calories >> shareable >> twoForOne >> abv >> volumeStr;

        // Convert attributes as needed based on item type
        if (itemType == 'a') {
            isShareable = (shareable == "y");
            isTwoForOne = (twoForOne == "y");
        }
        else if (itemType == 'b') {
            itemABV = std::stod(abv);
            volume = std::stoi(volumeStr);
        }

        // Create and add the item to the menu
        if (itemType == 'a') {
            menuItems.push_back(new Appetiser(itemName, price, calories, isShareable, isTwoForOne));
        }
        else if (itemType == 'm') {
            menuItems.push_back(new MainCourse(itemName, price, calories));
        }
        else if (itemType == 'b') {
            menuItems.push_back(new Beverage(itemName, price, calories, itemABV, volume));
        }
    }

    file.close();
}

Menu::~Menu() {
    // Clean up allocated memory for menu items
    for (Item* item : menuItems) {
        delete item;
    }
}

const Item* Menu::getItemByIndex(size_t index) const {
    if (index >= 1 && index <= menuItems.size()) {
        return menuItems[index - 1];
    }
    return nullptr;
}

void Menu::addItem(Item* item) {
    // Add an item to the menu (not implemented here, can be added if needed)
}

std::string Menu::toString() const {
    std::string result;
    std::vector<std::string> appetisers, mainCourses, beverages;

    for (size_t i = 0; i < menuItems.size(); ++i) {
        const Item* item = menuItems[i];
        std::string itemInfo = "(" + std::to_string(i + 1) + ") " + item->getName() +
            ": £" + std::to_string(item->getPrice()) +
            ", " + std::to_string(item->getCalories()) + " cal";

        if (const Appetiser* appetiser = dynamic_cast<const Appetiser*>(item)) {
            if (appetiser->isShareable()) {
                itemInfo += " (shareable)";
            }
            if (appetiser->isTwoForOne()) {
                itemInfo += " (2-4-1)";
            }
            appetisers.push_back(itemInfo);
        }
        else if (const Beverage* beverage = dynamic_cast<const Beverage*>(item)) {
            itemInfo += " (" + std::to_string(beverage->getVolume()) + "ml, " +
                std::to_string(beverage->getABV()) + "% abv)";
            beverages.push_back(itemInfo);
        }
        else if (dynamic_cast<const MainCourse*>(item)) {
            mainCourses.push_back(itemInfo);
        }
    }

    result += "Appetisers\n";
    for (const std::string& appetiser : appetisers) {
        result += appetiser + "\n";
    }

    result += "Main dishes\n";
    for (const std::string& mainCourse : mainCourses) {
        result += mainCourse + "\n";
    }

    result += "Beverages\n";
    for (const std::string& beverage : beverages) {
        result += beverage + "\n";
    }

    return result;
}


