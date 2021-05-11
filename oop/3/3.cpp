#include <string>
#include <iostream>

#include "date.h"

enum class Gender
{
    male,
    female,
    other
};

class Person
{
public:
    Person(const std::string &name, const Gender &gender, const Date &birthdate);
    std::string getName() const;
    Gender getGender() const;
    Date getBirthdate() const;

private:
    std::string name;
    Gender gender;
    Date birthdate;
};

Person::Person(const std::string &name, const Gender &gender, const Date &birthdate)
{
    this->name = name;
    this->gender = gender;
    this->birthdate = birthdate;
}

std::string Person::getName() const
{
    return name;
}

Gender Person::getGender() const
{
    return gender;
}

Date Person::getBirthdate() const
{
    return birthdate;
}

int main()
{
    Person p{"João António Semedo Pereira", Gender::male, Date{2002, 8, 21}};
    std::cout << p.getName() << "\n";
}
