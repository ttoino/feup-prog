#include <iostream>
#include <limits>

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
        if (a > b)
            a -= b;
        else
            b -= a;

    return a;
}

struct Fraction
{
    int numerator;
    int denominator;

    Fraction(int num = 0, int denom = 1)
    {
        int g = gcd(std::abs(num), std::abs(denom));

        if ((num < 0) == (denom < 0))
        {
            numerator = std::abs(num / g);
            denominator = std::abs(denom / g);
        }
        else
        {
            numerator = -std::abs(num / g);
            denominator = std::abs(denom / g);
        }
    }
};

Fraction operator-(const Fraction &f)
{
    return Fraction{-f.numerator, f.denominator};
}

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    return Fraction{f1.numerator * f2.denominator + f2.numerator * f1.denominator, f1.denominator * f2.denominator};
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    return f1 + (-f2);
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    return Fraction{f1.numerator * f2.numerator, f1.denominator * f2.denominator};
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    return Fraction{f1.numerator * f2.denominator, f1.denominator * f2.numerator};
}

std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    out << f.numerator;
    if (f.denominator != 1)
        out << '/' << f.denominator;
    return out;
}

bool readFraction(Fraction &f)
{
    char slash{};
    int numerator{};
    int denominator{};

    std::cin >> numerator >> slash >> denominator;

    if (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        slash = '\0';
    }
    if (slash != '/')
        return false;

    f = Fraction{numerator, denominator};
    return true;
}

int main()
{
    Fraction f1, f2;

    std::cout << "Please input a fraction (a/b): ";
    if (!readFraction(f1))
    {
        std::cerr << "Invalid fraction!\n";
        return 1;
    }

    std::cout << "And another: ";
    if (!readFraction(f2))
    {
        std::cerr << "Invalid fraction!\n";
        return 1;
    }

    std::cout << "Fraction A: " << f1
              << "\nFraction B: " << f2
              << "\nA + B: " << f1 + f2
              << "\nA - B: " << f1 - f2
              << "\nA × B: " << f1 * f2
              << "\nA ÷ B: " << f1 / f2 << '\n';
}
