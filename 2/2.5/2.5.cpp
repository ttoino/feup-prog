#include <iostream>
#include <complex>

int main()
{
    double a, b, c;
    std::cout << "Solution of ax^2 + bx + c = 0\nInput the coefficients (a b c): ";
    std::cin >> a >> b >> c;
    std::complex<double> temp = std::sqrt(std::complex<double>(b * b - 4 * a * c, 0)),
                         r1 = (-b + temp) / (2 * a),
                         r2 = (-b - temp) / (2 * a);

    if (r1.imag() || r2.imag())
        std::cout << "The equation has the complex roots " << r1.real() << " + " << r1.imag() << "i and " << r2.real() << " + " << r2.imag() << "i" << std::endl;
    else if (r1.real() == r2.real())
        std::cout << "The equation has the root " << r1.real() << std::endl;
    else
        std::cout << "The equation has the roots " << r1.real() << " and " << r2.real() << std::endl;
}