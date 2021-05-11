#pragma once
#include <string>

class Client
{
public:
    Client(std::string name, std::string address);
    std::string getName() const;
    std::string getAddress() const;

private:
    std::string name;
    std::string address;
};
