#include <iostream>

//Integer logic:
bool isIntegerPalindrome(unsigned number) {
	unsigned reverseNumber = 0, digit, originalNumber = number;

	do {
		digit = number % 10;
		reverseNumber = (reverseNumber * 10) + digit;
		number /= 10;
	} while (number != 0);

	return reverseNumber == originalNumber;
}

void printIsIntegerPalindrome(unsigned number) {
	if (isIntegerPalindrome(number)) {
		std::cout << "Number is palindrome" << std::endl;
	}
	else {
		std::cout << "Number is not palindrome" << std::endl;
	}
}

//String logic:
bool isStringPalindrome(const char* str) {
	int len = strlen(str);
	char* reversedStr = new char[len + 1];

	for (int i = 0; i < len; i++) {
		reversedStr[i] = str[len - i - 1];
	}
	reversedStr[len] = '\0';

	bool result = (strcmp(str, reversedStr) == 0);

	delete[] reversedStr;

	return result;
}

void printIsStringPalindrome(const char* str) {
	if (isStringPalindrome(str)) {
		std::cout << "String is palindrome" << std::endl;
	}
	else {
		std::cout << "String is not palindrome" << std::endl;
	}
}

//Main:
int main()
{
	int choice;
	std::cout << "Choose input type:" << std::endl;
	std::cout << "1. Number" << std::endl;
	std::cout << "2. String" << std::endl;
	std::cin >> choice;

	if (choice == 1) {
		unsigned number;
		std::cout << "Write a positive number: ";
		std::cin >> number;

		printIsIntegerPalindrome(number);
	}
	else {
		if (choice == 2) {
			const int MAX_LENGTH = 100;
			char str[MAX_LENGTH];
			std::cout << "Write a string: ";
			std::cin >> str;

			printIsStringPalindrome(str);
		}
		else {
			std::cout << "Invalid choice!" << std::endl;
		}
	}
}
