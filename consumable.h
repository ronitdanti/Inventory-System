#pragma once
#include "item.h"

class Consumable : public Item {
    std::string name;
    std::string description;
    int healAmount;
    
    public:
    Consumable(std::string n, std::string desc, int heal)
        : name(n), description(desc), healAmount(heal) {}

    std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    void use() override {
        std::cout << "You consume the " << name << " and heal " << healAmount << " HP.\n";
    }
    std::string getType() const override { return "Consumable"; }

    int getHealAmount() const { return healAmount; }
};