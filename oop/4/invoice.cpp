#include <vector>
#include <iostream>
#include <iomanip>

#include "item.h"
#include "client.h"
#include "invoice.h"

Invoice::Invoice(Client *client, const std::vector<Item> &items)
{
    this->items = items;
    this->client = client;
}

std::vector<Item> Invoice::getItems() const
{
    return items;
}

Client Invoice::getClient() const
{
    return *client;
}

void Invoice::addProduct(Product &product)
{
    for (auto i : items)
    {
        if (i.getProduct() == product)
        {
            i.setQuantity(i.getQuantity() + 1);
            return;
        }
    }

    items.push_back(Item{&product});
}

void Invoice::addItem(Item &item)
{
    for (auto i : items)
    {
        if (i.getProduct() == item.getProduct())
        {
            i.setQuantity(i.getQuantity() + item.getQuantity());
            return;
        }
    }

    items.push_back(item);
}

void Invoice::print(std::ostream &out) const
{
    out << std::fixed << std::setprecision(2)
        << client->getName() << "\n"
        << client->getAddress() << "\n\n"
        << std::left << std::setw(25) << "Description" << std::setw(8) << "Price" << std::setw(5) << "Qty"
        << "Total\n"
        << "------------------------ ------- ---- ---------\n";

    double total{0};
    for (auto i : items)
    {
        total += i.getPrice();
        Product product{i.getProduct()};
        out << std::left << std::setw(24) << product.getDescription()
            << std::right << std::setw(8) << product.getPrice()
            << std::setw(5) << i.getQuantity()
            << std::setw(10) << i.getPrice() << "\n";
    }

    out << "\nAmount due: " << total << "€\n";
}
