#include <iostream>
#include <cstdlib>

// 4.11 a) & c)
int ascending(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

// 4.11 b)
int descending(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

void printArray(int a[], size_t length)
{
    for (size_t i{0}; i < length; i++)
        std::cout << a[i] << " ";
}

int main()
{
    // 4.11 a)
    const size_t LENGTH{8};
    int a[LENGTH]{45, 32, 42, 12, 3, 4, 1, 5};

    std::cout << "Initial array: ";
    printArray(a, LENGTH);
    std::cout << '\n';

    qsort(a, LENGTH, sizeof(int), ascending);
    std::cout << "Sorted in ascending order: ";
    printArray(a, LENGTH);
    std::cout << '\n';

    // 4.11 b)
    int b[LENGTH]{45, 32, 42, 12, 3, 4, 1, 5};

    qsort(b, LENGTH, sizeof(int), descending);
    std::cout << "Sorted in descending order: ";
    printArray(b, LENGTH);
    std::cout << '\n';

    // 4.11 c)
    int c[LENGTH]{45, 32, 42, 12, 3, 4, 1, 5};

    qsort(c, LENGTH / 2, sizeof(int), ascending);
    qsort(c + LENGTH / 2, LENGTH / 2, sizeof(int), ascending);
    std::cout << "Sorted each half in ascending order: ";
    printArray(c, LENGTH);
    std::cout << '\n';
}