#include <string>

#include "client.h"

Client::Client(std::string name, std::string address)
{
    this->name = name;
    this->address = address;
}

std::string Client::getName() const
{
    return name;
}

std::string Client::getAddress() const
{
    return address;
}
