#pragma once
#include <string>

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
