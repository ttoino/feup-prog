#include <iostream>
#include <cmath>

bool isPrime(const unsigned long n)
{
    for (long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    unsigned long n;

    std::cout << "Please input a natural number: ";
    std::cin >> n;

    std::cout << "The number is " << (isPrime(n) ? "" : "not ")
              << "prime" << std::endl;
}