#include <iostream>
#include <climits>
#include <cmath>

int main()
{
    int n, length = 0, sum = 0, smallest = INT_MAX, largest = INT_MIN;

    while (true)
    {
        std::cin >> n;

        if (std::cin.fail() && std::cin.eof())
            break;

        length++;
        sum += n;
        if (n < smallest)
            smallest = n;
        if (n > largest)
            largest = n;
    }
    double mean = (double)sum / length;

    std::cout << "Σ = " << sum << "\nm = " << smallest << "\nM = " << largest << "\nμ = " << mean << std::endl;
}