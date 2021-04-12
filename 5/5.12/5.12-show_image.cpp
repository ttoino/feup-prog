#include <iostream>
#include <fstream>
#include <string>

using namespace std::literals;

const std::string black{"\e[40m  "s};
const std::string white{"\e[107m  "s};
const std::string reset{"\e[0m"s};

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;

    std::ifstream file(argv[1]);

    if (!file.is_open())
        return 2;

    size_t nLines{};
    size_t nColumns{};

    file >> nLines >> nColumns;

    for (size_t i{0}; i < nLines * nColumns; i++)
    {
        char c{};
        file >> c;

        if (i % nColumns == 0)
            std::cout << reset << "\n";

        std::cout << ((c == 'b') ? black : white);
    }

    std::cout << reset << "\n\n";
    file.close();
}
