#include <string>

#include "product.h"

Product::Product(std::string description, double price)
{
    this->description = description;
    this->price = price;
}

std::string Product::getDescription() const
{
    return description;
}

double Product::getPrice() const
{
    return price;
}

bool Product::operator==(const Product &other) const
{
    return description == other.description && price == other.price;
}
