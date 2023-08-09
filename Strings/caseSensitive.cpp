#include <iostream>

const int SIZE = 1024;

unsigned asciiDifference() {
    unsigned diff = 'A' - 'a';
    return diff;
}

void toUpper(char* str) {
    for (size_t i = 0; i < std::strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += asciiDifference();
        }
    }
}

void toLower(char* str) {
    for (size_t i = 0; i < std::strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] -= asciiDifference();
        }
    }
}

int main()
{
    std::cout << "Enter string: ";
    char* str = new char[SIZE];
    std::cin.getline(str, SIZE);

    char option;
    std::cout << "Choose an option: U for uppercase, L for lowercase: ";
    std::cin.get(option);
    std::cout << std::endl;

    if (option == 'U' || option == 'u') {
        toUpper(str);
        std::cout << str << std::endl;
    }
    else {
        if (option == 'L' || option == 'l') {
            toLower(str);
            std::cout << str << std::endl;
        }
        else {
            std::cout << "Invalid option" << std::endl;
        }
    }

   delete[] str;
}
