#pragma once
#include <string>

class Product
{
public:
    Product(std::string description, double price);

    std::string getDescription() const;
    double getPrice() const;

    bool operator==(const Product &other) const;

private:
    std::string description;
    double price;
};
