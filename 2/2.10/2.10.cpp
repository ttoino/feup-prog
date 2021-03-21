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
    uint n;

    std::cout << "Please input a number: ";
    std::cin >> n;

    std::cout << "The number's prime factors are:";
    uint i = 1;
    while (n > 1)
    {
        do
        {
            i++;
        } while (!isPrime(i));

        while (n % i == 0)
        {
            n /= i;
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}