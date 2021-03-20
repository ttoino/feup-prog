#include <iostream>

int main()
{
    char sep;
    int hours, minutes, seconds;
    std::cout << "Time 1 (hh:mm:ss): ";
    std::cin >> hours >> sep >> minutes >> sep >> seconds;
    int time1 = hours * 3600 + minutes * 60 + seconds;
    std::cout << "Time 2 (hh:mm:ss): ";
    std::cin >> hours >> sep >> minutes >> sep >> seconds;
    int time2 = hours * 3600 + minutes * 60 + seconds;
    int time = time1 + time2;
    std::cout << "Time 1 + Time 2 = " << time / 86400 << "d " << time % 86400 / 3600 << "h " << time % 3600 / 60 << "m " << time % 60 << "s" << std::endl;
}