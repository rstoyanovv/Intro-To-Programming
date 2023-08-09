#include <iostream>

const int MAX_SIZE = 128;

void replaceChar(char* str) {

    unsigned strLength = std::strlen(str);
    char currentSymbol = str[0];
    int currentIndex = 1;

    for (size_t i = 1; i < strLength; i++) {
        if (str[i] != currentSymbol) {
            str[currentIndex++] = str[i];
            currentSymbol = str[i];
        }
    }
    str[currentIndex] = '\0';
}

int main()
{
    char str[MAX_SIZE];
    std::cout << "Enter a string: ";
    std::cin.getline(str, MAX_SIZE);

    replaceChar(str);

    std::cout << str << std::endl;
}
