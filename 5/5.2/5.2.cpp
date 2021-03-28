#include <string>
#include <vector>
#include <iostream>

// 5.2 a)
void bubbleSort(std::vector<std::string> &v, char order)
{
    size_t size{v.size()};

    for (int i{0}; i < size - 1; i++)
    {
        bool swaped{false};

        for (int j{0}; j < size - i - 1; j++)
        {
            std::string &a{v.at(j)};
            std::string &b{v.at(j + 1)};

            if ((order == 'd' && a < b) || a > b)
            {
                std::string temp{b};
                b = a;
                a = temp;
                swaped = true;
            }
        }

        if (!swaped)
            return;
    }
}

// 5.2 b)
std::vector<std::string> readNames()
{
    std::vector<std::string> v{};
    std::cout << "Input a list of names:\n";
    while (true)
    {
        std::string s;
        std::getline(std::cin, s);

        if (std::cin.fail() && std::cin.eof())
        {
            std::cout << "\r\n";
            return v;
        }

        v.push_back(s);
    }
}

int main()
{
    std::vector<std::string> v{readNames()};

    std::cout << "Sorted in lexicographical order:\n";
    bubbleSort(v, 'a');
    for (std::string s : v)
        std::cout << s << '\n';

    std::cout << "\nSorted in reverse lexicographical order:\n";
    bubbleSort(v, 'd');
    for (std::string s : v)
        std::cout << s << '\n';
}
