#include "Menu.h"
#include "Order.h"
#include <iostream>
#include <sstream>

void displayHelp() {
    std::cout << "Available commands:\n"
        << "menu - Display the menu.\n"
        << "add [INDEX] - Add an item to the order by numeric index in the menu (starting at 1).\n"
        << "remove [INDEX] - Remove an item from the order by numeric index in the order (starting at 1).\n"
        << "checkout - Display the items in the order, the price, and discount savings.\n"
        << "help - Display this help menu.\n"
        << "exit - Terminate the program gracefully.\n";
}

int main() {
    Menu menu("menu.csv");
    Order order;

    std::string userCommand;

    while (userCommand != "exit") {
        std::cout << "> ";
        getline(std::cin, userCommand);

        std::istringstream iss(userCommand);
        std::string command;
        iss >> command;

        if (command == "menu") {
            std::cout << menu.toString();
        }
        else if (command == "add") {
            size_t index;
            if (iss >> index) {
                std::cout << "Parsed index: " << index << std::endl; // Debug output
                const Item* menuItem = menu.getItemByIndex(index);
                if (menuItem) {
                    order.addItem(menuItem);
                    std::cout << menuItem->getName() << " added to the order." << std::endl;
                }
                else {
                    std::cout << "Invalid item index. Please try again." << std::endl;
                }
            }
            else {
                std::cout << "Invalid command or invalid index format. Usage: add [INDEX]" << std::endl;
                std::cout << "Input string: " << userCommand << std::endl; // Debug output
            }
        }
        else if (command == "remove") {
            size_t index;
            if (iss >> index) {
                order.removeItem(index);
                std::cout << "Item removed from the order." << std::endl;
            }
            else {
                std::cout << "Invalid command. Usage: remove [INDEX]" << std::endl;
            }
        }
        else if (command == "checkout") {
            std::cout << "Order:\n";
            std::cout << order.toString();
            double total = order.calculateTotal();
            double savings = 0.0; // Assuming savings are calculated correctly
            std::cout << "Savings: £" << total - order.calculateTotal() << std::endl;
            std::cout << "Total: £" << total << std::endl;

            std::cout << "Would you like to complete your order? (yes/no): ";
            std::string completeOrder;
            getline(std::cin, completeOrder);

            if (completeOrder == "yes") {
                order.printReceipt();
                std::cout << "Receipt written to receipt.txt. Thank you for your order!" << std::endl;
                break;
            }
        }
        else if (command == "help") {
            displayHelp();
        }
        else if (command != "exit") {
            std::cout << "Invalid command. Type 'help' for available commands." << std::endl;
        }
    }

    return 0;
}
