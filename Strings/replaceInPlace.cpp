#include <iostream>
#pragma warning(disable: 4996);

const int MAX_LENGTH = 100;

void replace(char* str, const char* substring, const char* replacement) {
    int strLength = std::strlen(str);
    int subLength = std::strlen(substring);
    int replLength = std::strlen(replacement);

    for (size_t i = 0; i <= strLength; i++) {
        if (std::strncmp(str + i, substring, subLength) == 0) {
            if (subLength != replLength) {
                int shift = replLength - subLength;

                for (size_t j = strLength; j >= i + subLength; j--) {
                    str[j + shift] = str[j];
                }
            }

            for (size_t j = 0; j < replLength; j++) {
                str[i + j] = replacement[j];
            }

            i += replLength - 1;
            strLength += replLength - subLength;
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
    std::cout << string << std::endl;
}
