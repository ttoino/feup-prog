#include <iostream>
#include <cmath>
#include <limits>

bool isPrime(const unsigned long n)
{
    for (long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    unsigned long i = std::numeric_limits<unsigned long>::max();

    while (true)
    {
        if (isPrime(i))
        {
            std::cout << i << std::endl;
            return 0;
        }
        i--;
    }
}