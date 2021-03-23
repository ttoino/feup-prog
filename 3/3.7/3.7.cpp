#include <iostream>
#include <limits>

bool readInt(int &x)
{
    std::cin >> x;

    bool valid = !std::cin.fail() && std::cin.peek() == '\n';

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return valid;
}

int main()
{
    int number;

    std::cout << "Input a number: ";

    if (!readInt(number))
    {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    std::cout << "The number is " << number << std::endl;
}