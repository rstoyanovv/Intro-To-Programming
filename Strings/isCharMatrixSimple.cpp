#include <iostream>
#pragma warning (disable: 4996)

const int SIZE = 128;

bool isSimpleMatrix(char** matrix, unsigned size) {
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			if (matrix[i][j] < 'a' || matrix[i][j] > 'z') {
				return false;
			}
		}
	}
	return true;
}

int countOfStrInMatrix(char** matrix, unsigned size, char* str) {
	int count = 0;
	int strLength = std::strlen(str);

	//rows
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j <= size; j++) {
			bool match = true;
			for (size_t k = 0; k < strLength; k++) {
				if (matrix[i][j + k] != str[k]) {
					match = false;
					break;
				}
			}
			if (match) {
				count++;
			}
		}
	}

	//colomns
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			bool match = true;
			for (size_t k = 0; k < strLength; k++) {
				if (matrix[j + k][i] != str[k]) {
					match = false;
					break;
				}
			}
			if (match) {
				count++;
			}
		}
	}
	return count;
}

int main()
{
	unsigned n;
	char str[SIZE];

	std::cout << "Enter size of matrix: ";
	std::cin >> n;
	std::cin.ignore();

	char** matrix = new char* [n];
	for (size_t i = 0; i < n; i++) {
		matrix[i] = new char[n];
	}

	std::cout << "Enter a str:";
	std::cin.getline(str, SIZE);
	std::cout << std::endl;

	std::cout << "Enter matrix: " << std::endl;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			std::cin >> matrix[i][j];
		}
	}

	if (isSimpleMatrix(matrix, n)) {
		std::cout << "Matrix is simple";
	}
	else {
		std::cout << "Matrix is not simple";
	}

	std::cout << std::endl;
	std::cout << "Count of occurrences: " << countOfStrInMatrix(matrix, n, str) << std::endl;

	for (size_t i = 0; i < n; i++) {
		delete matrix[i];
	}
	delete[] matrix;

}
