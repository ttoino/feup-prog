#include <iostream>
#include <vector>
#include <random>

typedef std::vector<std::vector<uint>> plu;
typedef std::pair<int, int> date_t;

const int JAN{1},
    FEB{2},
    MAR{3},
    APR{4},
    MAY{5},
    JUN{6},
    JUL{7},
    AUG{8},
    SEP{9},
    OCT{10},
    NOV{11},
    DEC{12};

const char *MONTH_NAMES[]{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

const uint MAX_PLUVIOSITY{250};

bool isLeapYear(int year)
{
    return !(year % 400) || (year % 100 && !(year % 4));
}

int numDays(int year, int month)
{
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
    return -1;
}

plu readPluviosity(int year)
{
    srand(time(0));
    plu pluviosity{};

    for (int month{1}; month <= 12; month++)
    {
        plu::value_type monthPluviosity{};
        for (int day{1}; day <= numDays(year, month); day++)
        {
            monthPluviosity.push_back(rand() % (MAX_PLUVIOSITY + 1));
        }
        pluviosity.push_back(monthPluviosity);
    }
    return pluviosity;
}

std::vector<double> getMonthlyMean(plu pluviosity)
{
    std::vector<double> means{};
    for (int month{0}; month < pluviosity.size(); month++)
    {
        double mean{};
        plu::value_type monthPluviosity{pluviosity.at(month)};

        for (int day{0}; day < monthPluviosity.size(); day++)
        {
            mean += monthPluviosity.at(day);
        }

        mean /= monthPluviosity.size();
        means.push_back(mean);
    }
    return means;
}

double getDailyMean(plu pluviosity)
{
    double mean{0};
    std::vector<double> monthlyMeans{getMonthlyMean(pluviosity)};

    for (int i{0}; i < monthlyMeans.size(); i++)
        mean += monthlyMeans.at(i);

    mean /= monthlyMeans.size();
    return mean;
}

std::vector<date_t> getAboveAverageDates(plu pluviosity)
{
    double mean{getDailyMean(pluviosity)};
    std::vector<date_t> dates{};

    for (int month{0}; month < pluviosity.size(); month++)
    {
        plu::value_type monthPluviosity{pluviosity.at(month)};
        for (int day{0}; day < monthPluviosity.size(); day++)
            if (monthPluviosity.at(day) > mean)
                dates.push_back(date_t{day, month});
    }

    return dates;
}

std::vector<date_t> getMaxDates(plu pluviosity)
{
    std::vector<date_t> dates{};

    for (int month{0}; month < pluviosity.size(); month++)
    {
        plu::value_type monthPluviosity{pluviosity.at(month)};
        for (int day{0}; day < monthPluviosity.size(); day++)
            if (monthPluviosity.at(day) == MAX_PLUVIOSITY)
                dates.push_back(date_t{day, month});
    }

    return dates;
}

int main()
{
    int year{};

    std::cout << "Insert year: ";
    std::cin >> year;

    plu pluviosity{readPluviosity(year)};

    std::cout << "The average pluviosity was " << getDailyMean(pluviosity) << ".\n";

    auto monthlyMean{getMonthlyMean(pluviosity)};
    for (int month{0}; month < pluviosity.size(); month++)
        std::cout << "The average pluviosity for the month of " << MONTH_NAMES[month] << " was " << monthlyMean.at(month) << ".\n";

    auto aboveAveragedates{getAboveAverageDates(pluviosity)};
    std::cout << "The pluviosity was above average on ";
    for (int i{0}; i < aboveAveragedates.size(); i++)
    {
        if (i != 0)
            std::cout << ", ";

        date_t date{aboveAveragedates.at(i)};
        std::cout << date.first + 1 << '/' << date.second + 1;
    }
    std::cout << ".\n";

    auto maxDates{getMaxDates(pluviosity)};
    std::cout << "The pluviosity was the maximum on ";
    if (maxDates.size() == 0)
        std::cout << "no days";
    for (int i{0}; i < maxDates.size(); i++)
    {
        if (i != 0)
            std::cout << ", ";

        date_t date{maxDates.at(i)};
        std::cout << date.first + 1 << '/' << date.second + 1;
    }
    std::cout << ".\n";
}
