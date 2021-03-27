#include <vector>
#include <iostream>
#include <chrono>

// 4.3 a) & c)
void bubbleSort(std::vector<int> &v)
{
    size_t size{v.size()};

    for (int i = 0; i < size - 1; i++)
    {
        bool swaped{false};

        for (int j = 0; j < size - i - 1; j++)
        {
            int &a{v.at(j)};
            int &b{v.at(j + 1)};

            if (a > b)
            {
                int temp{b};
                b = a;
                a = temp;
                swaped = true;
            }
        }

        if (!swaped)
            return;
    }
}

// 4.3 d)
void bubbleSort(std::vector<int> &v, char order)
{
    size_t size{v.size()};

    for (int i = 0; i < size - 1; i++)
    {
        bool swaped{false};

        for (int j = 0; j < size - i - 1; j++)
        {
            int &a{v.at(j)};
            int &b{v.at(j + 1)};

            if (order == 'd')
            {
                if (a < b)
                {
                    int temp{b};
                    b = a;
                    a = temp;
                    swaped = true;
                }
            }
            else if (a > b)
            {
                int temp{b};
                b = a;
                a = temp;
                swaped = true;
            }
        }

        if (!swaped)
            return;
    }
}

// 4.3 d)
void bubbleSort(std::vector<int> &v, bool f(int x, int y))
{
    size_t size{v.size()};

    for (int i = 0; i < size - 1; i++)
    {
        bool swaped{false};

        for (int j = 0; j < size - i - 1; j++)
        {
            int &a{v.at(j)};
            int &b{v.at(j + 1)};

            if (!f(a, b))
            {
                int temp{b};
                b = a;
                a = temp;
                swaped = true;
            }
        }

        if (!swaped)
            return;
    }
}

bool ascending(int x, int y)
{
    return x < y;
}

bool descending(int x, int y)
{
    return x > y;
}

void printVector(std::vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
        std::cout << *i << ' ';
}

// 4.3 b)
int main()
{
    std::vector<int> v{45, 32, 42, 12, 3, 4, 1, 5};

    std::cout << "Initial vector: ";
    printVector(v);
    std::cout << "\nSorted (4.3 a): ";

    auto a{v};
    bubbleSort(a);
    printVector(a);

    std::cout << "\nSorted (4.3 d): ";

    auto d{v};
    bubbleSort(d, 'd');
    printVector(d);

    std::cout << "\nSorted (4.3 e ascending): ";

    auto e1{v};
    bubbleSort(e1, ascending);
    printVector(e1);

    std::cout << "\nSorted (4.3 e descending): ";

    auto e2{v};
    bubbleSort(e2, descending);
    printVector(e2);
    std::cout << "\n";
}