#include <iostream>
#include <cmath>

int main()
{
    uint n, x;

    std::cout << "n: ";
    std::cin >> n;
    std::cout << "x: ";
    std::cin >> x;

    double result = 1, last_term = 1;
    for (uint i = 1; i < n; i++)
    {
        last_term = -last_term * x / i;
        result += last_term;
    }

    std::cout << "e⁻ˣ ≈ " << result << std::endl;
}