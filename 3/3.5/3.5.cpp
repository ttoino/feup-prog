#include <iostream>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;

    return a;
}

void gcd(int a, int b, int &result)
{
    if (a == 0)
    {
        result = b;
        return;
    }
    if (b == 0)
    {
        result = a;
        return;
    }

    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;

    result = a;
}

int main()
{
    int a, b, result;

    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;

    gcd(a, b, result);
    std::cout << gcd(a, b) << "\t" << result << std::endl;
}