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

void vectorUnion(const std::vector<int> v1, const std::vector<int> v2, std::vector<int> &v3)
{
    v3 = v1;
    v3.insert(v3.end(), v2.begin(), v2.end());
    removeDuplicates(v3);
}

void vectorIntersection(const std::vector<int> v1, const std::vector<int> v2, std::vector<int> &v3)
{
    for (auto i{v1.begin()}, end{v1.end()}; i != end; i++)
        if (binarySearch(v1, *i) != -1 && binarySearch(v2, *i) != -1)
            v3.push_back(*i);

    removeDuplicates(v3);
}

void printVector(std::vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << ' ';
}

int main()
{
    std::vector<int> v1{1, 3, 5, 7};
    std::vector<int> v2{1, 2, 4, 6, 7};
    std::vector<int> u{};
    std::vector<int> i{};

    vectorUnion(v1, v2, u);
    vectorIntersection(v1, v2, i);

    std::cout << "v1: ";
    printVector(v1);
    std::cout << "\nv2: ";
    printVector(v2);
    std::cout << "\nv1 ∪ v2: ";
    printVector(u);
    std::cout << "\nv1 ∩ v2: ";
    printVector(i);
    std::cout << '\n';
}
