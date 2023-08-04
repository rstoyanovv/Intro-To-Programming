#include <iostream>

unsigned const MAX_SPACES = 1000;

void occupySpace(bool parking[], int parkingSpace) {
    if (parkingSpace <= MAX_SPACES) {
        parking[parkingSpace - 1] = true;
    }
}

void freeSpace(bool parking[], int parkingSpace) {
    if (parkingSpace <= MAX_SPACES) {
        parking[parkingSpace - 1] = false;
    }
}

int main()
{
    unsigned n;
    std::cin >> n;

    bool parking[MAX_SPACES] = { false };

    for (size_t i = 0; i < n; i++) {
        int parkingSpace;
        std::cin >> parkingSpace;

        if (parkingSpace > 0) {
            occupySpace(parking, parkingSpace);
        }
        else {
            if (parkingSpace < 0) {
                parkingSpace *= -1;
                freeSpace(parking, parkingSpace);
            }
        }
    }

    for (size_t i = 0; i < MAX_SPACES; i++) {
        if (parking[i]) {
            std::cout << i + 1 << " ";
        }
    }
    std::cout << std::endl;
}
