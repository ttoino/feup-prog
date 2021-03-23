#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double area(double radius)
{
    return M_PI * radius * radius;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = distance(x1, y1, x2, y2),
           b = distance(x2, y2, x3, y3),
           c = distance(x3, y3, x1, y1),
           s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double area(double x1, double y1, double x2, double y2)
{
    return std::abs(x2 - x1) * std::abs(y2 - y1);
}