#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std::literals;

int main()
{
    std::string filenamein{};
    std::vector<std::string> names{};
    std::getline(std::cin, filenamein);
    std::ifstream filein(filenamein);

    while (!filein.eof())
    {
        std::string name{};
        std::getline(filein, name);

        if (name == ""s)
            continue;

        names.push_back(name);
    }

    filein.close();

    std::sort(names.begin(), names.end());

    size_t i{filenamein.rfind('.')};
    std::ofstream fileout(filenamein.substr(0, i) + "_sorted"s + filenamein.substr(i, filenamein.length()));

    for (std::string name : names)
        fileout << name << "\n";

    fileout.close();
}
