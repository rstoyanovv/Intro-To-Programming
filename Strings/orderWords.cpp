#include <iostream>

const int MAX_WORDS_LENGTH = 50;

int compareWords(const char* word1, const char* word2) {
    return std::strcmp(word1, word2);
}

void insertionSort(char** words, int n) {
    for (size_t i = 1; i < n; i++) {
        char* currentWord = words[i];

        int j = i - 1;
        while (j >= 0 && compareWords(words[j], currentWord) > 0) {
            words[j + 1] = words[j];
            j--;
        }

        words[j + 1] = currentWord;
    }
}

int main()
{
    int n;
    std::cout << "Enter the number of words: ";
    std::cin >> n;
    std::cin.ignore();

    char** words = new char* [n];

    for (size_t i = 0; i < n; i++) {
        words[i] = new char[MAX_WORDS_LENGTH];

        std::cin.getline(words[i], MAX_WORDS_LENGTH);
    }

    insertionSort(words, n);

    for (size_t i = 0; i < n; i++) {
        std::cout << words[i] << std::endl;
        delete words[i];
    }

    delete[] words;
}
