#include <iostream>
#pragma warning(disable:4996)

const int SIZE = 1024;

char toLowerCase(char c) {
    return std::tolower(c);
}

bool isWordChar(char c) {
    return std::isalpha(c) || std::isdigit(c);
}

char* findMostCommonWord(const char* str) {
    int wordFreq[SIZE] = { 0 };
    char currentWord[SIZE];
    char mostCommonWord[SIZE];
    int maxFrequency = 0;
    
    int wordIndex = 0;
    bool inWord = false;

    for (size_t i = 0; str[i] != '\0'; i++) {
        
        if (isWordChar(str[i])) {
            currentWord[wordIndex++] = toLowerCase(str[i]);
            inWord = true;
        }
        else {
            if (inWord) {
                currentWord[wordIndex] = '\0';
                wordFreq[wordIndex]++;

                if (wordFreq[wordIndex] > maxFrequency) {
                    maxFrequency = wordFreq[wordIndex];
                    std::strcpy(mostCommonWord, currentWord);
                }
                wordIndex = 0;
                inWord = false;
            }
        }
    }
    
    char* result = new char[SIZE];
    std::strcpy(result, mostCommonWord);
    return result;
}

int main()
{
    char* str = new char[SIZE];
    std::cin.getline(str, SIZE);

    char* mostCommonStr = findMostCommonWord(str);

    std::cout << mostCommonStr << std::endl;

    delete[] str;
    delete[] mostCommonStr;
}
