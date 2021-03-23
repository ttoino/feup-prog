#include <iostream>
#include <climits>
#include <cmath>

int main()
{
    int n, length = 0, sum = 0, sum_sq = 0, smallest = INT_MAX, largest = INT_MIN;

    while (true)
    {
        std::cin >> n;

        if (!n)
            break;

        length++;
        sum += n;
        sum_sq += n * n;
        if (n < smallest)
            smallest = n;
        if (n > largest)
            largest = n;
    }
    double mean = (double)sum / length;
    double stdev = sqrt((sum_sq - 2 * sum * mean * length + mean * mean * length) / length);

    std::cout << "Σ = " << sum << "\nm = " << smallest << "\nM = " << largest << "\nμ = " << mean << "\nσ = " << stdev << std::endl;
}