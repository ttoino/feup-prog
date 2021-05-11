#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <ctime>

class Date
{
public:
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(std::string yearMonthDay); // yearMonthDaymust be in format "yyyy/mm/dd"
    Date();
    void setYear(unsigned int year);
    void setMonth(unsigned int month);
    void setDay(unsigned int day);
    void setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear() const;
    unsigned int getMonth() const;
    unsigned int getDay() const;
    std::string getDate() const; // returns the date in format "yyyy/mm/dd"
    void show() const;           // shows the date on the screen in format "yyyy/mm/dd"

    bool isValid() const;
    bool isEqualTo(const Date &date) const;
    bool isNotEqualTo(const Date &date) const;
    bool isAfter(const Date &date) const;
    bool isBefore(const Date &date) const;

private:
    unsigned int year;
    unsigned int month;
    unsigned int day;

    bool isLeapYear() const;
    int numDaysInMonth() const;
};

// a)
Date::Date(unsigned int year, unsigned int month, unsigned int day)
{
    setDate(year, month, day);
}

Date::Date(std::string yearMonthDay)
{
    unsigned int year, month, day;
    char slash;

    std::istringstream sin(yearMonthDay);
    sin >> year >> slash >> month >> slash >> day;
    setDate(year, month, day);
}

void Date::setYear(unsigned int year)
{
    this->year = year;
}

void Date::setMonth(unsigned int month)
{
    this->month = month;
}

void Date::setDay(unsigned int day)
{
    this->day = day;
}

void Date::setDate(unsigned int year, unsigned int month, unsigned int day)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

unsigned int Date::getYear() const
{
    return year;
}

unsigned int Date::getMonth() const
{
    return month;
}

unsigned int Date::getDay() const
{
    return day;
}

std::string Date::getDate() const
{
    std::ostringstream sout;
    sout << std::setfill('0') << std::setw(4) << year << '/' << std::setw(2) << month << '/' << std::setw(2) << day;
    return sout.str();
}

void Date::show() const
{
    std::cout << getDate() << '\n';
}

// c)
bool Date::isLeapYear() const
{
    return !(year % 400) || (year % 100 && !(year % 4));
}

int Date::numDaysInMonth() const
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return 28 + isLeapYear();
    }
    return -1;
}

bool Date::isValid() const
{
    return month > 0 && month <= 12 && day > 0 && day <= numDaysInMonth();
}

bool Date::isEqualTo(const Date &date) const
{
    return year == date.year && month == date.month && day == date.day;
}

bool Date::isNotEqualTo(const Date &date) const
{
    return !isEqualTo(date);
}

bool Date::isAfter(const Date &date) const
{
    return year > date.year || (year == date.year && (month > date.month || (month == date.month && day > date.day)));
}

bool Date::isBefore(const Date &date) const
{
    return year < date.year || (year == date.year && (month < date.month || (month == date.month && day < date.day)));
}

// f)
Date::Date()
{
    // auto now =  std::chrono::system_clock::now();
    auto now = std::time(nullptr);
    tm *t = std::localtime(&now);
    setDate(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

int main()
{
    // b)
    Date date("2002/08/21");
    date.show();

    // d)
    Date d;
    d.show();

    std::cout << date.isAfter(d) << " " << date.isBefore(d) << " " << date.isEqualTo(d) << "\n";
}
