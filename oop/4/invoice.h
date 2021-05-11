#pragma once

#include <vector>
#include <iostream>

#include "client.h"
#include "item.h"

class Invoice
{
public:
    Invoice(Client *client, const std::vector<Item> &items = {});

    std::vector<Item> getItems() const;
    Client getClient() const;

    void addProduct(Product &product);
    void addItem(Item &item);

    void print(std::ostream &out) const;

private:
    std::vector<Item> items;
    Client *client;
};
