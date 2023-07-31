#include <iostream>

unsigned reverseNumber(unsigned number) {
    unsigned reverseNumber = 0, digit;
  
    do {
        digit = number % 10;
        reverseNumber = (reverseNumber * 10) + digit;
        number /= 10;
    } while (number != 0);

    return reverseNumber;
}

int main()
{
    unsigned number, reverseNum;

    std::cout << "Write a positive number" << std::endl;
    std::cin >> number;

    reverseNum = reverseNumber(number);

    if (number == reverseNum) {
        std::cout << "Number is palindrome" << std::endl;
    }
    else {
        std::cout << "Number is not palindrome" << std::endl;
    }
}
