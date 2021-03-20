#include <iostream>

int main()
{
    double a, b, c;
    std::cout << "Please input three numbers: ";
    std::cin >> a >> b >> c;
    double largest = a, smallest = a;

    if (b > largest)
        largest = b;
    if (c > largest)
        largest = c;
    if (b < smallest)
        smallest = b;
    if (c < smallest)
        smallest = c;

    std::cout << "The largest number is " << largest << " and the smallest is " << smallest << std::endl;
}