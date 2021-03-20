#include <iostream>

int main()
{
    const double PI = 3.14159265359;
    double mass, rho, radius;
    std::cout << "Input the density of the sphere (Kg/m^3): ";
    std::cin >> rho;
    std::cout << "Input the radius of the sphere (m): ";
    std::cin >> radius;
    mass = 4. / 3. * rho * PI * radius * radius * radius;
    std::cout << "The mass of the sphere is " << mass << "Kg" << std::endl;
}
