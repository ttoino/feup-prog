#include <iostream>
#include <climits>
#include <cmath>

int main()
{
    uint length;
    int n, sum = 0, smallest = INT_MAX, largest = INT_MIN;

    std::cout << "length: ";
    std::cin >> length;

    for (uint i = 0; i < length; i++)
    {
        std::cin >> n;
        sum += n;
        if (n < smallest)
            smallest = n;
        if (n > largest)
            largest = n;
    }
    double mean = (double)sum / length;

    std::cout << "Σ = " << sum << "\nm = " << smallest << "\nM = " << largest << "\nμ = " << mean << std::endl;
}