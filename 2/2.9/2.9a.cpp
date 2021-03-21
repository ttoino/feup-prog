#include <iostream>

int main()
{
    uint n;

    std::cout << "Input a 3 digit number: ";
    std::cin >> n;

    if (n > 999)
    {
        std::cerr << "That's not 3 digits\n";
        return 1;
    }

    uint firstDigit = n / 100, lastDigit = n % 10;

    std::cout << "The number is " << (firstDigit == lastDigit ? "" : "not ") << "a palyndrome" << std::endl;
}