#include <string>

bool sequenceSearch(std::string s, int n, char c)
{
    return s.find(std::string(n, c)) != std::string::npos;
}