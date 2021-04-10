#include <iostream>
#include <vector>
#include <cmath>

struct Point
{
    double x;
    double y;
};

struct Polygon
{
    std::vector<Point> points;
};

int main()
{
    size_t nPoints{};
    Polygon polygon{};

    std::cout << "How many points the polygon has: ";
    std::cin >> nPoints;

    for (size_t i{0}; i < nPoints; i++)
    {
        Point p{};
        std::cout << "Point " << i + 1 << ": ";
        std::cin >> p.x >> p.y;
        polygon.points.push_back(p);
    }

    double area{0};
    for (size_t i{0}; i < polygon.points.size(); i++)
    {
        Point p1{polygon.points.at(i)};
        Point p2{polygon.points.at((i + 1) % polygon.points.size())};

        area += p1.x * p2.y - p2.x * p1.y;
    }
    area = fabs(area / 2);

    std::cout << "The area of the polygon is " << area << "\n";
}
