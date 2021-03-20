#include <iostream>

int main()
{
    double a, b, c, temp;
    std::cout << "Please input three positive numbers: ";
    std::cin >> a >> b >> c;

    if (a < 0 || b < 0 || c < 0)
    {
        std::cerr << "The numbers must be positive!\n";
        return 1;
    }

    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (c > b)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > a)
    {
        temp = a;
        a = b;
        b = temp;
    }

    if (b + c < a)
        std::cout << "The numbers can't represent the sides of a triangle!" << std::endl;
    else
        std::cout << "The numbers represent the sides of a triangle!" << std::endl;
}