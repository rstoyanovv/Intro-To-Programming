#include <iostream>

const char* m[] = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz",
};

void makeCombinations(const char* digits, char* currString, int index, int n)
{
    if (index == n)
    {
        currString[index] = '\0';
        std::cout << currString << '\n';
        return;
    }

    char currentNumber = digits[index];
    int currentIndex = currentNumber - '0';
    const char* currentChars = m[currentIndex];
    int length = std::strlen(currentChars);

    for (size_t i = 0; i < length; i++)
    {
        char letter = currentChars[i];
        currString[index] = letter;
        makeCombinations(digits, currString, index + 1, n);
    }
}

void letterCombinations(const char* digits) {
    int n = std::strlen(digits);

    if (n == 0) {
        return;
    }

    char* currentStr = new char[n + 1];
    makeCombinations(digits, currentStr, 0, n);
    delete[] currentStr;
}

int main()
{
    letterCombinations("76756");
}
