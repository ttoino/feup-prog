#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Point
{
    double x;
    double y;
};

struct Polygon
{
    size_t nPoints;
    struct Point *points;
};

int main()
{
    struct Polygon polygon;

    printf("How many points the polygon has: ");
    scanf("%u", &polygon.nPoints);

    polygon.points = (struct Point *)malloc(sizeof(struct Point) * polygon.nPoints);

    for (size_t i = 0; i < polygon.nPoints; i++)
    {
        printf("Point %u: ", i + 1);
        scanf("%f %f", &polygon.points[i].x, &polygon.points[i].y);
    }

    double area = 0;
    for (size_t i = 0; i < polygon.nPoints; i++)
    {
        struct Point p1 = polygon.points[i];
        struct Point p2 = polygon.points[(i + 1) % polygon.nPoints];

        area += p1.x * p2.y - p2.x * p1.y;
    }
    area = fabs(area / 2);

    printf("The area of the polygon is %f\n", area);

    free(polygon.points);
}
