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
    for (int i = 2; i < 1000; i++)
        if (isPrime(i))
            std::cout << i << "\t";

    std::cout << std::endl;
}