#include <iostream>
#include <cstring>

const size_t STRING_SIZE{256};

void readNames(char a[][STRING_SIZE], size_t amount)
{
    std::cout << "Input a list of names (max " << STRING_SIZE << " chars per name):\n";

    for (size_t i{0}; i < amount; i++)
    {
        std::cin.getline(a[i], STRING_SIZE);
    }
}

int ascending(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int descending(const void *a, const void *b)
{
    return -strcmp((char *)a, (char *)b);
}

int main()
{
    size_t length{};

    std::cout << "Number of names: ";
    std::cin >> length;

    char a[length][STRING_SIZE]{};
    std::cin.ignore();
    readNames(a, length);

    std::cout << "\nSorted in lexicographical order:\n";
    qsort(a, length, STRING_SIZE * sizeof(char), ascending);
    for (auto s : a)
        std::cout << s << '\n';

    std::cout << "\nSorted in reverse lexicographical order:\n";
    qsort(a, length, STRING_SIZE * sizeof(char), descending);
    for (auto s : a)
        std::cout << s << '\n';
}