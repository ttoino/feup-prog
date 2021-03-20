#include <iostream>
#include <cmath>

int main()
{
    uint32_t weight;
    std::cout << "Please input package weight: ";
    std::cin >> weight;
    float price = 5;

    if (weight > 1000)
    {
        weight -= 1000;
        price += 7.5 + ceil(weight / 250.) * 5;
    }
    else if (weight > 500)
    {
        weight -= 500;
        price += ceil(weight / 100.) * 1.5;
    }

    std::cout << "The price is " << price << "€" << std::endl;
}