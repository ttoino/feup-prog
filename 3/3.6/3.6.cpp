#include <iostream>
#include <ctime>

time_t timeElapsed()
{
    static const time_t firstCall = time(nullptr);

    return time(nullptr) - firstCall;
}

int main()
{
    std::cout << "Hit enter to get the time elapsed";

    while (true)
    {
        std::cin.get();
        std::cout << "\r" << timeElapsed();
    }
}