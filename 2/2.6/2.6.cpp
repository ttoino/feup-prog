#include <iostream>
#include <cmath>

int main()
{
    double n, q, j;
    std::cout << "n q j: ";
    std::cin >> n >> q >> j;
    j /= 100;
    double finalAmount = q * pow(1 + j, n);
    std::cout << "The amount of money after " << n << " years is " << finalAmount << std::endl;
}