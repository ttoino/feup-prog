#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 1;

    std::ifstream filein(argv[1]);
    std::ofstream fileout(argv[2]);

    if (!filein.is_open())
        return 2;

    size_t nLines{};
    size_t nColumns{};

    filein >> nLines >> nColumns;
    fileout << nLines << ' ' << nColumns << ' ';

    for (size_t i{0}; i < nLines * nColumns;)
    {
        size_t count{};
        char c{};
        filein >> count >> c;
        fileout << std::string(count, c);
        i += count;
    }

    filein.close();
    fileout.close();
}
