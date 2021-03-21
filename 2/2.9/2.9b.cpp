#include <iostream>
#include <cmath>

int numDigits(int n)
{
    int r = 0;

    while (n > 0)
    {
        n /= 10;
        r++;
    }

    return r;
}

int main()
{
    uint n;

    std::cout << "Please input a number: ";
    std::cin >> n;

    bool pal = true;
    while (n > 10)
    {
        uint ndigits = numDigits(n);
        uint first = n / pow(10, ndigits - 1), last = n % 10;

        if (first != last)
        {
            pal = false;
            break;
        }

        n = n % (int)pow(10, ndigits - 1) / 10;
    }

    std::cout << "The number is " << (pal ? "" : "not ") << "a palyndrome" << std::endl;
}