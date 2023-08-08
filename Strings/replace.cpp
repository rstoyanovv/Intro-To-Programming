#include <iostream>
#pragma warning(disable: 4996);

const int MAX_LENGTH = 100;

void replace(char* str, const char* substring, const char* replacement) {
    int strLength = std::strlen(str);
    int subLength = std::strlen(substring);
    int replLength = std::strlen(replacement);

    for (size_t i = 0; i <= strLength - subLength; i++) {
        if (std::strncmp(str + i, substring, subLength) == 0) {
            char temp[MAX_LENGTH];
            std::strcpy(temp, str + i + subLength);
            std::strcpy(str + i, replacement);
            std::strcpy(str + i + replLength, temp);
            i += replLength - 1;
        }
    }
}

int main()
{
    char string[MAX_LENGTH];
    char substring[MAX_LENGTH];
    char replacement[MAX_LENGTH];
    
    std::cout << "Enter a string: ";
    std::cin.getline(string, MAX_LENGTH);

    std::cout << "Enter a substring: ";
    std::cin.getline(substring, MAX_LENGTH);

    std::cout << "Enter a replacement: ";
    std::cin.getline(replacement, MAX_LENGTH);

    replace(string, substring, replacement);
    std::cout << string;
}
