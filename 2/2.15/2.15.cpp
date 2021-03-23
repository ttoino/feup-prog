#include <iostream>
#include <random>
#include <ctime>

int main()
{
    srand(time(nullptr));
    int a = 2 + rand() % 8, b = 2 + rand() % 8, result = a * b, input;

    std::cout << a << " × " << b << " = ";
    time_t start = time(nullptr);
    std::cin >> input;
    double t = difftime(time(nullptr), start);

    if (result != input)
        std::cout << "Very Bad" << std::endl;
    else if (t > 10)
        std::cout << "Insufficient" << std::endl;
    else if (t > 5)
        std::cout << "Satisfactory" << std::endl;
    else
        std::cout << "Good" << std::endl;
}