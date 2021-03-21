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
    int amount = 0, i = 2;

    while (amount < 100)
    {
        if (isPrime(i))
        {
            std::cout << i << "\t";
            amount++;
        }
        i++;
    }
    std::cout << std::endl;
}