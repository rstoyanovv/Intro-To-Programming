#include <iostream>
#include <cstring>

char toLower(char ch) {
    return (ch >= 'A' && ch <= 'Z') ? (ch + 'a' - 'A') : ch;
}

const char* lexicographicallySmallestWord(const char* input) {
    const char* smallestWord = nullptr;
    int wordStart = -1;

    for (int i = 0; input[i] != '\0'; ++i) {
        char ch = toLower(input[i]);

        if ((ch >= 'a' && ch <= 'z') || ch == '\'') {
            if (wordStart == -1) {
                wordStart = i;
            }
        } else {
            if (wordStart != -1) {
                const char* word = &input[wordStart];

                if (smallestWord == nullptr || std::strcmp(word, smallestWord) < 0) {
                    smallestWord = word;
                }

                wordStart = -1;
            }
        }
    }

    if (wordStart != -1) {
        const char* word = &input[wordStart];

        if (smallestWord == nullptr || std::strcmp(word, smallestWord) < 0) {
            smallestWord = word;
        }
    }

    return smallestWord;
}

int main() {
    const char* input = "Me? Why always me?";
    const char* result = lexicographicallySmallestWord(input);

    if (result != nullptr) {
        std::cout << "Lexicographically smallest word: " << result << std::endl; // always
    } else {
        std::cout << "No word found." << std::endl;
    }

    return 0;
}
