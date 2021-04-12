#include <iostream>
#include <fstream>

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

    char last{' '};
    size_t counter{0};
    for (size_t i{0}; i < nLines * nColumns; i++)
    {
        char c{};
        filein >> c;

        if (last != c)
        {
            if (counter > 0)
                fileout << counter << last;

            counter = 1;
        }
        else
        {
            counter++;
        }

        last = c;
    }
    fileout << counter << last;

    filein.close();
    fileout.close();
}
