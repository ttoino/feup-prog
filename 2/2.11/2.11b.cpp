#include <iostream>
#include <cmath>

int main()
{
    uint n;

    std::cout << "n: ";
    std::cin >> n;

    double result = 1, last_term = 1;
    for (uint i = 1; i < n; i++)
    {
        last_term /= i;
        result += last_term;
    }

    std::cout << "e ≈ " << result << std::endl;
}