#pragma once
#include "product.h"

class Item
{
public:
    Item(Product *product, unsigned int quantity = 1);

    Product getProduct() const;
    unsigned int getQuantity() const;
    double getPrice() const;

    void setQuantity(unsigned int quantity);

private:
    Product *product;
    unsigned int quantity;
};
