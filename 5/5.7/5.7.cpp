#include <iostream>

struct Date
{
    uint year;
    uint month;
    uint day;
};

// 5.7 a)
void readDate(Date *d)
{
    char slash{};

    std::cin >> d->year >> slash >> d->month >> slash >> d->day;
}

// 5.7 b)
void writeDate(const Date *d)
{
    std::cout << d->year << '/' << d->month << '/' << d->day;
}

// 5.7 c)
int compareDates(const Date *d1, const Date *d2)
{
    auto sign{[](int x) { return (x > 0) - (x < 0); }};
    int x{d1->year - d2->year};

    if (x)
        return sign(x);
    else if (x = d1->month - d2->month)
        return sign(x);
    else if (x = d1->day - d2->day)
        return sign(x);
    else
        return 0;
}

// 5.7 d)
void sortDates(Date *d1, Date *d2)
{
    if (compareDates(d1, d2) > 0)
        std::swap(*d1, *d2);
}

// 5.7 e)
int main()
{
    Date d1{};
    Date d2{};

    std::cout << "Input a date (YYYY/M/DD): ";
    readDate(&d1);
    std::cout << "And another: ";
    readDate(&d2);

    std::cout << compareDates(&d1, &d2) << ' ' << compareDates(&d2, &d1) << '\n';

    sortDates(&d1, &d2);

    std::cout << "The dates in order are ";
    writeDate(&d1);
    std::cout << " and ";
    writeDate(&d2);
    std::cout << "\n";
}
