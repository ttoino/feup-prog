#include <string>

bool sequenceSearch(std::string s, int n, char c)
{
    int count{0};

    for (char cs : s)
        if (cs == c)
            count = 0;
        else if (++count == n)
            return true;

    return false;
}