#include <iostream>
#include <string>
#include <vector>

// 5.9 a)
struct Address
{
    std::string city;
    std::string street;
    uint doorNumber;
};

enum Gender
{
    male,
    female,
    other
};

// 5.9 b)
struct Person
{
    std::string name;
    uint age;
    Gender gender;
    Address address;
};

std::istream &operator>>(std::istream &in, Address &a)
{
    std::cout << "City: ";
    if (in.peek() == '\n')
        in.ignore(1, '\n');
    std::getline(in, a.city);
    std::cout << "Street: ";
    if (in.peek() == '\n')
        in.ignore(1, '\n');
    std::getline(in, a.street);
    std::cout << "Door number: ";
    in >> a.doorNumber;

    return in;
}

std::istream &operator>>(std::istream &in, Person &p)
{
    std::cout << "Name: ";
    if (in.peek() == '\n')
        in.ignore(1, '\n');
    std::getline(in, p.name);

    if (p.name == "")
        return in;

    std::cout << "Age: ";
    in >> p.age;
    std::cout << "Gender (m/f/?): ";
    std::string gender;
    if (in.peek() == '\n')
        in.ignore(1, '\n');
    std::getline(in, gender);
    p.gender = gender == "m" ? Gender::male : (gender == "f" ? Gender::female : Gender::other);
    in >> p.address;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Person &p)
{
    out << (p.gender == Gender::male ? "\033[1;34m" : (p.gender == Gender::female ? "\033[1;95m" : "\033[1;90m")) << p.name << " (" << p.age << ")\033[0m";

    return out;
}

// 5.9 c)
int main()
{
    std::cout << "Input a set of people's data (leave name blank to finish)\n";

    std::vector<Person> people{};
    while (true)
    {
        std::cout << '\n';
        Person p{};
        std::cin >> p;
        if (std::cin.fail() || p.name == "")
            break;

        people.push_back(p);
    }

    std::cout << "\nStreet name to search for: ";

    std::string streetName{};
    if (std::cin.peek() == '\n')
        std::cin.ignore(1, '\n');
    std::getline(std::cin, streetName);

    std::cout << "\nPeople that live on that street:";
    for (Person p : people)
    {
        if (p.address.street == streetName)
            std::cout << " " << p;
    }
    std::cout << '\n';
}
