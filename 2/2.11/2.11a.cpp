#include <iostream>
#include <cmath>

int main()
{
    uint n;

    std::cout << "n: ";
    std::cin >> n;

    double result;
    for (uint i = 0; i < n; i++)
        result += (i % 2 == 0 ? 1 : -1) * 4. / (2 * i + 1);

    std::cout << "π ≈ " << result << std::endl;
}