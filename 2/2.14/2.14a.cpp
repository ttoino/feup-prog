#include <iostream>

int main()
{
    uint maxIter;
    double n, rq = 1, rqn = 1, delta, dif;

    std::cout << "n: ";
    std::cin >> n;
    std::cout << "Precision: ";
    std::cin >> delta;
    std::cout << "Max iterations: ";
    std::cin >> maxIter;

    for (int i = 0; i < maxIter; i++)
    {
        rq = rqn;
        rqn = (rq + n / rq) / 2;
        dif = n - rqn * rqn;
        if (std::abs(dif) < delta)
            break;
    }

    std::cout << "√n ≈ " << rqn << std::endl;
}