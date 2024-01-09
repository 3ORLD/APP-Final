#pragma once
#include "ItemList.h"
#include <string>

class Menu : public ItemList {
public:
    const Item* getItemByIndex(size_t index) const;
    Menu(const std::string& filePath); // Constructor that loads menu from a file
    ~Menu() override; // Destructor to clean up allocated memory

    void addItem(Item* item) override;
    std::string toString() const override;

private:
    std::vector<Item*> menuItems; // Vector to store menu items
};

