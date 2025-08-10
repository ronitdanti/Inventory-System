#pragma once
#include "item.h"

class Weapon : public Item {
    std::string name;
    std::string description;
    int damage;

    public:
    Weapon(std::string n, std::string desc, int dmg)
        : name(n), description(desc), damage(dmg) {}
    
    std::string getName() const override { return name; }
    std::string getDescription() const override {return description; }
    void use() override {
        std::cout << "You can't use a weapon like this. Equip it instead.\n";
    }
    std::string getType() const override { return "Weapon"; }

    int getDamage() const { return damage; }
};