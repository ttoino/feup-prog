#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

struct EuroMillionsBet
{
    std::vector<uint> mainNumbers;
    std::vector<uint> luckyStars;
};

template <class T>
void removeDuplicates(std::vector<T> &v)
{
    size_t size = v.size();

    for (size_t i{0}; i < size; i++)
    {
        T a{v.at(i)};

        for (size_t j{i + 1}; j < size; j++)
            if (v.at(j) == a)
            {
                size--;
                for (size_t k{j}; k < size; k++)
                    v.at(k) = v.at(k + 1);
            }
    }

    v.resize(size);
}

template <class T>
int binarySearch(const std::vector<T> v, T value)
{
    long first{0};
    long last{v.size() - 1};
    long middle{};

    while (first <= last)
    {
        middle = first + (last - first) / 2;

        if (v.at(middle) == value)
            return middle;
        else if (v.at(middle) > value)
            last = middle - 1;
        else
            first = middle + 1;
    }

    return -1;
}

template <class T>
std::vector<T> intersection(const std::vector<T> v1, const std::vector<T> v2)
{
    std::vector<T> result{};
    for (auto i : v1)
        if (binarySearch(v2, i) != -1)
            result.push_back(i);

    removeDuplicates(result);
    return result;
}

int main()
{
    EuroMillionsBet userBet{};
    EuroMillionsBet key{};
    uint x{};

    srand(time(nullptr));

    std::cout << "Enter 5 numbers for your guess: "
                 "\033[38;2;255;0;0m";
    for (size_t i{0}; i < 5; i++)
    {
        std::cin >> x;
        userBet.mainNumbers.push_back(x);
        key.mainNumbers.push_back(1 + rand() % 50);
    }

    std::cout << "\033[0m"
                 "Enter 2 lucky numbers for your guess: "
                 "\033[38;2;255;255;0m";
    for (size_t i{0}; i < 2; i++)
    {
        std::cin >> x;
        userBet.luckyStars.push_back(x);
        key.luckyStars.push_back(1 + rand() % 12);
    }

    std::sort(userBet.mainNumbers.begin(), userBet.mainNumbers.end());
    std::sort(userBet.luckyStars.begin(), userBet.luckyStars.end());
    std::sort(key.mainNumbers.begin(), key.mainNumbers.end());
    std::sort(key.luckyStars.begin(), key.luckyStars.end());

    std::cout << "\033[0m"
                 "The key was"
                 "\033[38;2;255;0;0m";
    for (auto i : key.mainNumbers)
        std::cout << ' ' << i;

    std::cout << "\033[38;2;255;255;0m";
    for (auto i : key.luckyStars)
        std::cout << ' ' << i;
    std::cout << "\033[0m"
                 "\n";

    EuroMillionsBet commonNumbers{};
    commonNumbers.mainNumbers = intersection(userBet.mainNumbers, key.mainNumbers);
    commonNumbers.luckyStars = intersection(userBet.luckyStars, key.luckyStars);
    std::cout << "\033[0m"
                 "Your correct numbers were"
                 "\033[38;2;255;0;0m";
    for (auto i : commonNumbers.mainNumbers)
        std::cout << ' ' << i;

    std::cout << "\033[38;2;255;255;0m";
    for (auto i : commonNumbers.luckyStars)
        std::cout << ' ' << i;
    std::cout << "\033[0m"
                 "\n";
}
