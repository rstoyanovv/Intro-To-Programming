#include <iostream>

const int MAX_SIZE = 1024;

int wordsCounter(char str[MAX_SIZE]) {
    unsigned length = strlen(str);
    int cnt = 0;

    for (size_t i = 0; i < length; i++) {
        if (str[i] == ' ') {
            cnt++;
        }
    }

    return cnt + 1;
}

int main()
{
    char str[MAX_SIZE];
    std::cin.getline(str, MAX_SIZE);

    std::cout << "Count of words is: " << wordsCounter(str) << std::endl;
}
