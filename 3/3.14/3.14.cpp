#include <iostream>
#include <cmath>

double integrateTR(double f(double), double a, double b, int n)
{
    double h = (b - a) / n, area = 0;

    for (int i = 0; i < n; i++)
        area += h / 2 * (f(a + i * h) + f(a + (i + 1) * h));

    return area;
}

int main()
{
    const auto g = [](double x) { return x * x; };
    const auto h = [](double x) { return sqrt(4 - x * x); };

    int n;

    std::cout << "n: ";
    std::cin >> n;

    std::cout << "∫ x² dx ≈ " << integrateTR(g, 0, 10, n) << " from x=0 to x=10\n";
    std::cout << "∫ √(4 - x²) dx ≈ " << integrateTR(h, -2, 2, n) << " from x=-2 to x=2\n";
}