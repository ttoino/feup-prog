#include <iostream>

int main()
{
    int32_t a, b;
    int64_t sum;
    std::cout << "Input two integers: ";
    std::cin >> a >> b;
    sum = a + b;

    if (sum > INT32_MAX)
        std::cout << "Sum overflow" << std::endl;
    else if (sum < INT32_MIN)
        std::cout << "Sum underflow" << std::endl;
    else
        std::cout << a + b << std::endl;
}