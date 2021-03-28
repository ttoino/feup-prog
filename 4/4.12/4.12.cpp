#include <iostream>
#include <limits>

// 4.12 a)
void readArray(int *&a, size_t length)
{
    a = new int[length];

    for (int i{0}; i < length; i++)
    {
        int v{};
        std::cout << "Index " << i << ": ";
        std::cin >> v;
        a[i] = v;
    }
}

int findValueInArray(int *const a, size_t length, int value, size_t pos1 = 0, size_t pos2 = std::numeric_limits<size_t>::max())
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

size_t findMultValuesInArray(int *const a, size_t length, int value, size_t pos1, size_t pos2, size_t *&index)
{
    size_t *temp = new size_t[length];

    if (pos2 >= length)
        pos2 = length - 1;

    size_t count = 0;
    for (size_t i{pos1}; i <= pos2; i++)
    {
        if (a[i] == value)
            temp[count++] = i;
    }

    index = new size_t[count];
    for (size_t i{0}; i < count; i++)
        index[i] = temp[i];

    delete[] temp;

    return count;
}

// 4.12 b)
int findValueInArray(int *const pos1, int *const pos2, int value)
{
    for (int *i{pos1}; i <= pos2; i++)
    {
        if (*i == value)
            return (int)(i - pos1);
    }

    return -1;
}

size_t findMultValuesInArray(int *const pos1, int *const pos2, int value, size_t *&index)
{
    size_t *temp = new size_t[pos2 - pos1];

    size_t count = 0;
    for (int *i{pos1}; i <= pos2; i++)
    {
        if (*i == value)
            temp[count++] = (size_t)(i - pos1);
    }

    index = new size_t[count];
    for (size_t i{0}; i < count; i++)
        index[i] = temp[i];

    delete[] temp;

    return count;
}

int main()
{
    // 4.12 a)
    size_t length{};
    int *a;
    int value{};

    std::cout << "Size of the array you want: ";
    std::cin >> length;
    readArray(a, length);

    std::cout << "Value to search for: ";
    std::cin >> value;

    std::cout << "The first index of " << value << " is " << findValueInArray(a, length, value) << '\n';
    std::cout << "All the indices of " << value << " are ";

    size_t *indices;
    size_t ilength = findMultValuesInArray(a, length, value, 0, length - 1, indices);
    for (size_t i{0}; i < ilength; i++)
        std::cout << indices[i] << ' ';

    std::cout << '\n';

    // 4.12 b)
    std::cout << "The first index of " << value << " is " << findValueInArray(a, a + length - 1, value) << '\n';
    std::cout << "All the indices of " << value << " are ";

    ilength = findMultValuesInArray(a, a + length - 1, value, indices);
    for (size_t i{0}; i < ilength; i++)
        std::cout << indices[i] << ' ';

    std::cout << '\n';
}