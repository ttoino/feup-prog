#include <iostream>
#include <limits>
#include <vector>

// 4.2 a)
void readVector(std::vector<int> &v, size_t length)
{
    int a{};
    for (int i{0}; i < length; i++)
    {
        std::cout << "Index " << i << ": ";
        std::cin >> a;
        v.push_back(a);
    }
}

int findValueInArray(const std::vector<int> v, int value, size_t pos1 = 0, size_t pos2 = std::numeric_limits<size_t>::max())
{
    if (pos2 >= v.size())
        pos2 = v.size() - 1;

    for (size_t i{pos1}; i <= pos2; i++)
    {
        if (v.at(i) == value)
            return i;
    }

    return -1;
}

void findMultValuesInArray(const std::vector<int> v, int value, size_t pos1, size_t pos2, std::vector<size_t> &index)
{
    if (pos2 >= v.size())
        pos2 = v.size() - 1;

    for (int i = pos1; i <= pos2; i++)
    {
        if (v.at(i) == value)
            index.push_back(i);
    }
}

// 4.2 b)
void readVector(std::vector<int> &v)
{
    int a{};
    size_t i{0};
    while (true)
    {
        std::cout << "Index " << i++ << ": ";
        std::cin >> a;

        if (std::cin.fail() && std::cin.eof())
        {
            std::cin.clear();
            std::cout << '\r';
            return;
        }

        v.push_back(a);
    }
}

//4.2 c)
std::vector<int> readVector()
{
    std::vector<int> v{};
    int a{};
    size_t i{0};
    while (true)
    {
        std::cout << "Index " << i++ << ": ";
        std::cin >> a;

        if (std::cin.fail())
        {
            if (std::cin.eof())
            {
                std::cout << '\r';
                return v;
            }

            std::cin.clear();
        }

        v.push_back(a);
    }
}

std::vector<int> findMultValuesInArray(const std::vector<int> v, int value, size_t pos1 = 0, size_t pos2 = std::numeric_limits<size_t>::max())
{
    std::vector<int> index{};

    if (pos2 >= v.size())
        pos2 = v.size() - 1;

    for (int i = pos1; i <= pos2; i++)
    {
        if (v.at(i) == value)
            index.push_back(i);
    }

    return index;
}

int main()
{
    int value{0};

    std::cout << "Please input a vector\n";
    std::vector<int> v{readVector()};

    // Can't get input after eof 🙃
    // std::cout << "Value to search for: ";
    // std::cin >> value;

    std::cout << "The first index of " << value << " is " << findValueInArray(v, value) << '\n';
    std::cout << "All the indices of " << value << " are ";

    std::vector<int> indices{findMultValuesInArray(v, value)};
    for (size_t i{0}; i < indices.size(); i++)
        std::cout << indices.at(i) << ' ';

    std::cout << '\n';
}
