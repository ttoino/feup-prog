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

// int lcm(int a, int b)
// {
//     if (a == 0 && b == 0)
//         return 0;
//
//     return std::abs(a * b) / gcd(a, b);
// }

bool readFraction(int &numerator, int &denominator)
{
    char slash;

    std::cin >> numerator >> slash >> denominator;

    if (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        slash = '\0';
    }
    if (slash != '/')
    {
        numerator = 0;
        denominator = 0;
        return false;
    }

    return true;
}

void reduceFraction(int &numerator, int &denominator)
{
    int g = gcd(std::abs(numerator), std::abs(denominator));

    if ((numerator < 0) == (denominator < 0))
    {
        numerator = std::abs(numerator / g);
        denominator = std::abs(denominator / g);
    }
    else
    {
        numerator = -std::abs(numerator / g);
        denominator = std::abs(denominator / g);
    }
}

void addFractions(int n1, int d1, int n2, int d2, int &nr, int &dr)
{
    nr = n1 * d2 + n2 * d1;
    dr = d1 * d2;
    reduceFraction(nr, dr);
}

void subFractions(int n1, int d1, int n2, int d2, int &nr, int &dr)
{
    addFractions(n1, d1, -n2, d2, nr, dr);
}

void mulFractions(int n1, int d1, int n2, int d2, int &nr, int &dr)
{
    nr = n1 * n2;
    dr = d1 * d2;
    reduceFraction(nr, dr);
}

void divFractions(int n1, int d1, int n2, int d2, int &nr, int &dr)
{
    mulFractions(n1, d1, d2, n2, nr, dr);
}

int main()
{
    int n1, d1, n2, d2, na, da, ns, ds, nm, dm, nd, dd;

    std::cout << "Please input a fraction (a/b): ";
    if (!readFraction(n1, d1))
    {
        std::cerr << "Invalid fraction!\n";
        return 1;
    }

    std::cout << "And another: ";
    if (!readFraction(n2, d2))
    {
        std::cerr << "Invalid fraction!\n";
        return 1;
    }

    reduceFraction(n1, d1);
    reduceFraction(n2, d2);
    addFractions(n1, d1, n2, d2, na, da);
    subFractions(n1, d1, n2, d2, ns, ds);
    mulFractions(n1, d1, n2, d2, nm, dm);
    divFractions(n1, d1, n2, d2, nd, dd);

    std::cout << "Fraction A: " << n1 << '/' << d1
              << "\nFraction B: " << n2 << '/' << d2
              << "\nA + B: " << na << '/' << da
              << "\nA - B: " << ns << '/' << ds
              << "\nA × B: " << nm << '/' << dm
              << "\nA ÷ B: " << nd << '/' << dd << std::endl;
}
