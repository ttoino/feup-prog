#include <iostream>
#include <vector>

void removeDuplicates(std::vector<int> &v)
{
    size_t size = v.size();

    for (size_t i{0}; i < size; i++)
    {
        int a{v.at(i)};

        for (size_t j{i + 1}; j < size; j++)
            if (v.at(j) == a)
            {
                size--;
                for (size_t k{j}; k < size; k++)
                    v.at(k) = v.at(k + 1);
            }
    }

    v.resize(size);
}

void printVector(std::vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << ' ';
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 2, 5, 6, 5, 4, 6, 7, 2, 2, 8, 9, 9, 10, 1, 10, 8, 9, 1, 3, 5};

    std::cout << "Initial vector: ";
    printVector(v);
    std::cout << "\nWithout duplicates: ";
    removeDuplicates(v);
    printVector(v);
    std::cout << '\n';
}
