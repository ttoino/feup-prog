#include <iostream>
#include <limits>

// 4.1 a)
void readArray(int a[], size_t length)
{
    for (int i{0}; i < length; i++)
    {
        std::cout << "Index " << i << ": ";
        std::cin >> a[i];
    }
}

// 4.1 b) & d)
int findValueInArray(const int a[], size_t length, int value, size_t pos1 = 0, size_t pos2 = std::numeric_limits<size_t>::max())
{
    if (pos2 >= length)
        pos2 = length - 1;

    for (size_t i{pos1}; i <= pos2; i++)
    {
        if (a[i] == value)
            return i;
    }

    return -1;
}

// 4.1 e)
size_t findMultValuesInArray(const int a[], size_t length, int value, size_t pos1, size_t pos2, size_t index[])
{
    if (pos2 >= length)
        pos2 = length - 1;

    int count = 0;
    for (size_t i{pos1}; i <= pos2; i++)
    {
        if (a[i] == value)
            index[count++] = i;
    }

    return count;
}

// 4.1 c) & f)
int main()
{
    const size_t SIZE{10};
    int a[SIZE]{};
    int value{};

    std::cout << "Please input a " << SIZE << " element array\n";
    readArray(a, SIZE);

    std::cout << "Value to search for: ";
    std::cin >> value;

    std::cout << "The first index of " << value << " is " << findValueInArray(a, SIZE, value) << '\n';
    std::cout << "All the indices of " << value << " are ";

    size_t indices[SIZE]{};
    size_t length = findMultValuesInArray(a, SIZE, value, 0, SIZE - 1, indices);
    for (size_t i{0}; i < length; i++)
        std::cout << indices[i] << ' ';

    std::cout << '\n';
}
