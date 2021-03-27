#include <iostream>
#include <vector>

int binarySearch(const std::vector<int> v, int value)
{
    int first{0};
    int last{v.size() - 1};
    int middle{};

    while (first <= last)
    {
        middle = first + (last - first) / 2;

        if (v.at(middle) == value)
            return middle;
        else if (v.at(middle) > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return -1;
}

void printVector(std::vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << ' ';
}

int main()
{
    std::vector<int> v{-1234, -23, -4, -2, 0, 1, 4, 7, 20, 123};

    std::cout << "v: ";
    printVector(v);
    std::cout << "\nThe value 0 is at index " << binarySearch(v, 0)
              << "\nThe value -1234 is at index " << binarySearch(v, -1234)
              << "\nThe value 5 is at index " << binarySearch(v, 5) << '\n';
}
