#include <iostream>

int main()
{
    int a, b, c;
    std::cout << "Please, input 3 integer numbers\nA: ";
    std::cin >> a;
    std::cout << "B: ";
    std::cin >> b;
    std::cout << "C: ";
    std::cin >> c;
    double mean = (a + b + c) / 3.;
    std::cout << "mean\t= " << mean << "\nA-mean\t= " << a - mean << "\nB-mean\t= " << b - mean << "\nC-mean\t= " << c - mean << std::endl;
}