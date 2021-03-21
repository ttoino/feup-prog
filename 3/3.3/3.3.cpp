#include <iostream>

double sqrt(double n, double delta, uint maxIter)
{
    double rq = 1, rqn = 1, dif;

    for (int i = 0; i < maxIter; i++)
    {
        rq = rqn;
        rqn = (rq + n / rq) / 2;
        dif = n - rqn * rqn;
        if (std::abs(dif) < delta)
            break;
    }

    return rqn;
}

int main()
{
    uint maxIter;
    double n, delta;

    std::cout << "n: ";
    std::cin >> n;
    std::cout << "Precision: ";
    std::cin >> delta;
    std::cout << "Max iterations: ";
    std::cin >> maxIter;

    double result = sqrt(n, delta, maxIter);

    std::cout << "√n ≈ " << result << std::endl;
}