#include <iostream>
#include <iomanip>
#include <vector>

const size_t NE{5};
const char RESET[]{"\033[31;1;0m"};
const char GRAY[]{"\033[38;2;100;100;100m"};
const char RED[]{"\033[38;2;255;0;0m"};

// 4.7 a)
void localMax(const int m[NE][NE])
{
    std::cout << GRAY << "   0  1  2  3  4\n";

    for (size_t i{0}; i < NE; i++)
    {
        std::cout << GRAY << i << ' ';

        for (size_t j{0}; j < NE; j++)
        {
            int a{m[i][j]};

            // bool localMax{false};
            // if (i != 0 && j != 0 && i != NE - 1 && j != NE - 1)
            //     if (m[i - 1][j - 1] < a && m[i - 1][j] < a && m[i - 1][j + 1] < a && m[i][j - 1] < a && m[i][j + 1] < a && m[i + 1][j - 1] < a && m[i + 1][j] < a && m[i + 1][j + 1] < a)
            //         localMax = true;

            // Equivalent to commented code above
            bool localMax{(i != 0 && j != 0 && i != NE - 1 && j != NE - 1) && (m[i - 1][j - 1] < a && m[i - 1][j] < a && m[i - 1][j + 1] < a && m[i][j - 1] < a && m[i][j + 1] < a && m[i + 1][j - 1] < a && m[i + 1][j] < a && m[i + 1][j + 1] < a)};

            std::cout << (localMax ? RED : RESET) << std::setw(2) << a << ' ';
        }

        std::cout << '\n';
    }

    std::cout << RESET;
}

// 4.7 c)
void localMax(const std::vector<std::vector<int>> v, bool any = false)
{
    std::cout << GRAY << "   0  1  2  3  4\n";

    for (size_t i{0}; i < v.size(); i++)
    {
        std::cout << GRAY << i << ' ';
        std::vector<int> sv{v.at(i)};

        for (size_t j{0}; j < sv.size(); j++)
        {
            int a{sv.at(j)};

            bool localMax{true};

            if (any || (i > 0 && j > 0 && i < v.size() - 1 && j < sv.size() - 1))
            {
                for (int x = -1; x <= 1; x++)
                    for (int y = -1; y <= 1; y++)
                        if (i + x >= 0 && i + x < v.size() && j + y >= 0 && j + y < sv.size() && v.at(i + x).at(j + y) > a)
                            localMax = false;
            }
            else
            {
                localMax = false;
            }

            std::cout << (localMax ? RED : RESET) << std::setw(2) << a << ' ';
        }

        std::cout << '\n';
    }

    std::cout << RESET;
}

// 4.7 b)
int main()
{
    int m[NE][NE]{
        {7, 3, 4, 1, 3},
        {2, 9, 6, 2, 1},
        {1, 3, 5, 1, 4},
        {6, 5, 2, 7, 5},
        {4, 2, 1, 3, 6}};

    localMax(m);

    std::cout << '\n';

    std::vector<std::vector<int>> v{
        {7, 3, 4, 1, 3},
        {2, 9, 6, 2, 1},
        {1, 3, 5, 1, 4},
        {6, 5, 2, 7, 5},
        {4, 2, 1, 3, 6}};

    localMax(v);

    std::cout << '\n';

    localMax(v, true);
}
