#include <iostream>

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    std::cout << "Enter a input: ";
    std::cin.getline(input, MAX_LENGTH);

    int numbers[MAX_LENGTH];
    char operators[MAX_LENGTH];
    int numIndex = 0;
    int opIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (isDigit(input[i])) {
            int num = input[i] - '0';
            while (isDigit(input[i + 1])) {
                num = num * 10 + (input[i + 1] - '0');
                ++i;
            }
            numbers[numIndex++] = num;
        }
        else if (input[i] == '*' || input[i] == '+') {
            while (opIndex > 0 && operators[opIndex - 1] == '*' && input[i] == '+') {
                int b = numbers[--numIndex];
                int a = numbers[--numIndex];
                char op = operators[--opIndex];
                numbers[numIndex++] = (op == '*') ? a * b : a + b;
            }
            operators[opIndex++] = input[i];
        }
    }

    while (opIndex > 0) {
        int b = numbers[--numIndex];
        int a = numbers[--numIndex];
        char op = operators[--opIndex];
        numbers[numIndex++] = (op == '*') ? a * b : a + b;
    }

    std::cout << "Result: " << numbers[0] << std::endl;

    return 0;
}
