#include "inventory.h"
#include "player.h"
#include "weapon.h"
#include "consumable.h"

#include <iostream>

int main() {
    Inventory inventory;
    Player player;

    inventory.addItem(std::make_unique<Weapon>("Sword", "A simple steel sword.", 15));
    inventory.addItem(std::make_unique<Consumable>("Health Potion", "Restores 20 HP.", 20));

    std::string input;
    while (true) {
        std::cout << "\nEnter command: list, use [#], equip [#], status, quit\n> ";
        std::getline(std::cin, input);

        if (input == "list") {
            inventory.listItems();
        } else if (input.rfind("use", 0) == 0) {
            int index = std::stoi(input.substr(4)) - 1;
            Item* item = inventory.getItem(index);
            if (!item) {
                std::cout << "Invalid item.\n";
                continue;
            }
            if (item->getType() == "Consumable") {
                player.useConsumable(static_cast<Consumable*>(item));
                inventory.removeItem(index);
            } else {
                item->use(); // calls polymorphic fallback for unusable items
            }
        } else if (input.rfind("equip", 0) == 0) {
            int index = std::stoi(input.substr(6)) - 1;
            Item* item = inventory.getItem(index);
            if (!item || item->getType() != "Weapon") {
                std::cout << "Can't equip that item.\n";
            } else {
                player.equipWeapon(static_cast<Weapon*>(item));
            }
        } else if (input == "status") {
            player.showStatus();
        } else if (input == "quit") {
            break;
        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}