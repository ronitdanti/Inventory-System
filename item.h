#pragma once
#include <string>
#include <iostream>

class Item {
    public:
    virtual ~Item() {}
    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
    virtual void use() = 0;
    virtual std::string getType() const = 0;
};