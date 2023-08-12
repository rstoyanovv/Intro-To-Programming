#include <iostream>

const int MAX_LENGTH = 1024;

int maxMoves(const char* row, int startIndex) {
	int currentMove = 0;
	int currentIndex = startIndex;

		while (row[currentIndex] != '\0') {
			if (row[currentIndex] == 'r') {
				currentMove++;
				break;
			}

			if (row[currentIndex] == 'g') {
				currentIndex++;
				currentMove++;
			}

			if (row[currentIndex] == 'y') {
				//currentMove++;
				while (row[currentIndex] != 'g') {
					currentIndex++;
					if (row[currentIndex] == '\0') {
						return -1;
					}
				}
			}
		}
	return currentMove;
}

int main()
{
	char input[MAX_LENGTH];

	std::cin.getline(input, MAX_LENGTH);

	int cntMaxMoves = 0;

	for (size_t i = 0; input[i] != '\0'; i++) {
		int currentMaxMoves = maxMoves(input, i);
		if (currentMaxMoves > cntMaxMoves) {
			cntMaxMoves = currentMaxMoves;
		}
	}

	std::cout << cntMaxMoves << std::endl;
	
}
