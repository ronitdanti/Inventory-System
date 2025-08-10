#pragma once
#include "weapon.h"
#include "consumable.h"
#include <memory>

class Player {
    int hp;
    std::unique_ptr<Weapon> equippedWeapon;

    public:
    Player() : hp(100) {}

    void equipWeapon(Weapon* weapon) {
        equippedWeapon = std::make_unique<Weapon>(*weapon);
        std::cout << "Equipped " << equippedWeapon->getName() << ".\n";
    }

    void useConsumable(Consumable* consumable) {
        hp += consumable->getHealAmount();
        if (hp > 100) hp = 100;
        consumable->use();
        std::cout << "Current HP: " << hp << "\n";
    }

    void showStatus() const {
        std::cout << "HP: " << hp << "\n";
        if (equippedWeapon)
            std::cout << "Equipped Weapon: " << equippedWeapon->getName() << "\n";
        else
            std::cout << "No weapon equipped.\n";
    }
};