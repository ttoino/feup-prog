#include <iostream>

int main()
{
    double a, b, c, d, e, f;
    std::cout << "a·x + b·y = c\nd·x + e·y = f\na: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    std::cout << "d: ";
    std::cin >> d;
    std::cout << "e: ";
    std::cin >> e;
    std::cout << "f: ";
    std::cin >> f;

    double x = (c * e - b * f) / (a * e - b * d), y = (a * f - c * d) / (a * e - b * d);
    std::cout << "x = " << x << "\ny = " << y << std::endl;
}