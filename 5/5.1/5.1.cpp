#include <iostream>
#include <string>

// 5.1 a)
char encryptChar(char c, int key)
{
    while (key < 0)
        key += 26;

    if (c >= 'a' && c <= 'z')
        return (c - 'a' + key) % 26 + 'a';

    if (c >= 'A' && c <= 'Z')
        return (c - 'A' + key) % 26 + 'A';

    return c;
}

// 5.1 b)
std::string encryptString(std::string s, int key)
{
    for (char &c : s)
        c = encryptChar(c, key);

    return s;
}

// 5.1 d)
void encryptString(char s[], int key, char out[])
{
    int i{0};
    do
        out[i] = encryptChar(s[i], key);
    while (s[i++]);
}

int main()
{
    // 5.1 c)
    std::string s{};
    int key{};

    std::cout << "String to encrypt: ";
    std::getline(std::cin, s);
    std::cout << "Key: ";
    std::cin >> key;

    std::cout << encryptString(s, key) << '\n';

    //5.1 d)
    char cs[256];
    char out[256];

    std::cout << "C-String to encrypt (max 255 chars): ";
    std::cin.ignore();
    std::cin.getline(cs, 256);
    std::cout << "Key: ";
    std::cin >> key;

    encryptString(cs, key, out);
    std::cout << out << '\n';
}
