#include <iostream>

int main()
{
    double a, b, c, temp;
    std::cout << "Please input three numbers: ";
    std::cin >> a >> b >> c;

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

    std::cout << "The numbers in descending order are " << a << ", " << b << ", " << c << std::endl;
}