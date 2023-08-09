#include <iostream>

const int MAX_SIZE = 32;

int countDigits(int num) {
    int count = 0;

    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

void intToString(int num, char* str) {
    int length = countDigits(num);
    int index = length - 1;

    while (num != 0) {
        int digit = num % 10;
        str[index--] = '0' + digit;
        num /= 10;
    }

    str[length] = '\0';
}

int main()
{
    int num;
    char str[MAX_SIZE];
    std::cin >> num;

    intToString(num, str);
    std::cout << "String: " << str << std::endl;

}
