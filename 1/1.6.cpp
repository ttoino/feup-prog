#include <stdio.h>
#include <iostream>
#include <math.h>

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    char sep;
    std::cout << "Enter three point coordinates (x, y): ";
    std::cin >> sep >> x1 >> sep >> y1 >> sep;
    std::cin >> sep >> x2 >> sep >> y2 >> sep;
    std::cin >> sep >> x3 >> sep >> y3 >> sep;
    double a = dist(x1, y1, x2, y2), b = dist(x2, y2, x3, y3), c = dist(x3, y3, x1, y1);
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    std::cout << "area = " << area << std::endl;
}