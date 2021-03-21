#include <iostream>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = distance(x1, y1, x2, y2),
           b = distance(x2, y2, x3, y3),
           c = distance(x3, y3, x1, y1),
           s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    char sep;
    std::cout << "Enter three point coordinates (x, y): ";
    std::cin >> sep >> x1 >> sep >> y1 >> sep;
    std::cin >> sep >> x2 >> sep >> y2 >> sep;
    std::cin >> sep >> x3 >> sep >> y3 >> sep;
    std::cout << "area = " << area(x1, y1, x2, y2, x3, y3) << std::endl;
}