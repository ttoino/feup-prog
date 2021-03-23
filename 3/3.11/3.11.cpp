#include <iostream>

int gcd(int m, int n)
{
    if (m % n)
        return gcd(n, m % n);

    return n;
}

int main()
{
    int m, n;

    std::cout << "Please input two numbers: ";
    std::cin >> m >> n;

    std::cout << "Their greatest common divisor is " << gcd(m, n) << std::endl;
}
