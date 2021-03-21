#include <iostream>
#include <iomanip>
#include <cmath>

//TODO
int main()
{
    std::cout << std::setw(3) << "ang"
              << "\t"
              << std::setw(8) << "sin"
              << "\t"
              << std::setw(8) << "cos"
              << "\t"
              << std::setw(8) << "tan"
              << "\n";
    std::cout << std::fixed << std::setprecision(6);
    for (int i = 0; i <= 90; i += 15)
    {
        double r = i / 180. * M_PI;
        std::cout << std::setw(3) << i << "\t"
                  << std::setw(8) << sin(r) << "\t"
                  << std::setw(8) << cos(r) << "\t"
                  << std::setw(8) << tan(r) << "\n";
    }
}