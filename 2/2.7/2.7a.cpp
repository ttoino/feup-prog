#include <iostream>
#include <cmath>

int main()
{
    unsigned long n, i;
    bool prime = true;

    std::cout << "Please input a natural number: ";
    std::cin >> n;

    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }

    std::cout << "The number is " << (prime ? "" : "not ")
              << "prime" << std::endl;
}