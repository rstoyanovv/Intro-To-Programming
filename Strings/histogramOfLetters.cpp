#include <iostream>

int main()
{
    const int ALPHABET_SIZE = 26;
    int letterCounts[ALPHABET_SIZE] = { 0 };

    std::cout << "Enter a string of lowercase letters: ";
    char c;

    while (std::cin.get(c) && c != '\n') {
        if (c >= 'a' && c <= 'z') {
            letterCounts[c - 'a']++;
        }
    }

    for (size_t i = 0; i < ALPHABET_SIZE; i++) {
        if (letterCounts[i] > 0) {
            char letter = 'a' + i;
            std::cout << letter << ": " << letterCounts[i] << std::endl;
        }
    }
}
