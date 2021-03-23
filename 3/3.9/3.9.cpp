#include <iostream>
#include <iomanip>
#include <cassert>

// Months
const int JAN = 1,
          FEB = 2,
          MAR = 3,
          APR = 4,
          MAY = 5,
          JUN = 6,
          JUL = 7,
          AUG = 8,
          SEP = 9,
          OCT = 10,
          NOV = 11,
          DEC = 12;

const char *MONTHS[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Days of the week
const int SUN = 0,
          MON = 1,
          TUE = 2,
          WED = 3,
          THU = 4,
          FRI = 5,
          SAT = 0;

const char *WEEKDAYS[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Month code table
const int C_TABLE[12][2] = {{0, 6}, {3, 2}, {3, 3}, {6, 6}, {1, 1}, {4, 4}, {6, 6}, {2, 2}, {5, 5}, {0, 0}, {3, 3}, {5, 5}};

bool isLeapYear(int year)
{
    return !(year % 400) || (year % 100 && !(year % 4));
}

int numDays(int year, int month)
{
    if (month < JAN || month > DEC)
        return -1;

    switch (month)
    {
    case JAN:
    case MAR:
    case MAY:
    case JUL:
    case AUG:
    case OCT:
    case DEC:
        return 31;
    case APR:
    case JUN:
    case SEP:
    case NOV:
        return 30;
    case FEB:
        return 28 + isLeapYear(year);
    }
}

int weekDay(int year, int month, int day)
{
    int a = year % 100, s = year / 100, c = C_TABLE[month - 1][isLeapYear(year)];

    return (5 * a / 4 + c + day - 2 * (s % 4) + 6) % 7;
}

void printFirst3Chars(const char *str)
{
    std::cout << *str << *(str + 1) << *(str + 2);
}

void printMonth(int year, int month)
{
    std::cout << MONTHS[month - 1] << ' ' << year << std::endl;
    for (int weekDay = 0; weekDay < 7; weekDay++)
    {
        printFirst3Chars(WEEKDAYS[weekDay]);
        std::cout << ' ';
    }
    std::cout << '\n';

    int md = numDays(year, month);
    for (int day = 1; day <= md; day++)
    {
        int wd = weekDay(year, month, day);
        if (day == 1)
            for (int i = 0; i < wd; i++)
                std::cout << "    ";

        std::cout << std::setw(3) << day << ' ';

        if (wd == 6 && day != md)
            std::cout << '\n';
    }
    std::cout << '\n';
}

void printYear(int year)
{
    for (int month = 1; month <= 12; month++)
    {
        printMonth(year, month);
        std::cout << '\n';
    }
}

int main()
{
    // TEST isLeapYear()
    // assert(isLeapYear(2004));
    // assert(isLeapYear(2000));
    // assert(!isLeapYear(2021));
    // assert(!isLeapYear(1900));

    // TEST weekDay()
    // int year, month, day;
    // char sep;
    // std::cout << "Please input a date (YYYY/M/D): ";
    // std::cin >> year >> sep >> month >> sep >> day;
    // std::cout << weekDay(year, month, day) << std::endl;

    // TEST printMonth()
    // int year, month;
    // char sep;
    // std::cout << "Please input a month (YYYY/M): ";
    // std::cin >> year >> sep >> month;
    // printMonth(year, month);

    //TEST printYear()
    int year;
    std::cout << "Please input a year: ";
    std::cin >> year;
    printYear(year);
}