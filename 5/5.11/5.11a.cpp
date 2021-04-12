#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std::literals;

int main()
{
    std::string filename{};
    std::vector<std::string> names{};
    std::getline(std::cin, filename);
    std::ifstream file(filename);

    while (!file.eof())
    {
        std::string name{};
        std::getline(file, name);

        if (name == ""s)
            continue;

        names.push_back(name);
    }

    file.close();

    std::sort(names.begin(), names.end());

    for (std::string name : names)
        std::cout << name << "\n";
}
