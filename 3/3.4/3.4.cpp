#include <iostream>
#include <cmath>

double round(double x, uint n)
{
    int temp = pow(10, n);
    return floor(x * temp + .5) / temp;
}

int main()
{
    double x;
    uint n;

    std::cout << "x: ";
    std::cin >> x;
    std::cout << "n: ";
    std::cin >> n;

    std::cout << round(x, n) << std::endl;
}