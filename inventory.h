#pragma once
#include "item.h"
#include <vector>
#include <memory>

class Inventory {
    std::vector<std::unique_ptr<Item>> items;
    size_t capacity;

    public:
    Inventory(size_t cap = 10) : capacity(cap) {}

    bool addItem(std::unique_ptr<Item> item) {
        if (items.size() >= capacity) {
            std::cout << "Inventory full!\n";
            return false;
        }
        items.push_back(std::move(item));
        return true;
    }

    void listItems() const {
        std::cout << "Inventory:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << i +  1 << ". " << items[i]->getName() << " (" << items[i]->getType() << ")\n";
        }
    }

    Item* getItem(size_t index) {
        if (index >= items.size()) return nullptr;
        return items[index].get();
    }

    std::unique_ptr<Item> removeItem(size_t index) {
        if (index >= items.size()) return nullptr;
        auto ptr = std::move(items[index]);
        items.erase(items.begin() + index);
        return ptr;
    }

    size_t size() const { return items.size(); }
};