#include <iostream>

bool property1(int arr[], unsigned size) {
    for (size_t i = 0; i < size - 1; i++) {
        if (arr[i] % 2 == arr[i + 1] % 2) {
            return false;
        }
    }
    return true;
}

bool property2(int arr[], unsigned size) {
    for (size_t i = 1; i < size - 1; i+=2) {
        if (arr[i] != arr[i - 1] + arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int countDigits(int number) {
    if (number == 0)
        return 1;

    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }

    return count;
}

int negativeIntoPositive(int number) {

    if (number < 0) {
        number = -number;
    }
    return number;
}

bool containsNumber(int number, int digits) {
    if (number == 0 && digits == 0) {
        return true;
    }
        
    negativeIntoPositive(number);
    negativeIntoPositive(digits);

    int digitCount = countDigits(digits);
    int residue = 1;

    for (int i = 0; i < digitCount; i++)
    {
        residue *= 10;
    }

    while (number > 0) {
        if (number % residue == digits)
            return true;

        number /= 10;
    }

    return false;
}

bool property3(int arr[], unsigned size) {
    for (size_t i = 0; i < size; i++) {
        if (!containsNumber(arr[i], i)) {
            return false;
        }
    }
    return true;
}

int main()
{
    unsigned n;
    std::cin >> n;

    int* array = new int[n];
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    if (property1(array, n)) {
        std::cout << "Property 1" << std::endl;
    }

    if (property2(array, n)) {
        std::cout << "Property 2" << std::endl;
    }

    if (property3(array, n)) {
        std::cout << "Property 3" << std::endl;
    }

    if (!property1(array, n) && !property2(array, n) && !property3(array, n)) {
        std::cout << "There is no fulfilled properties!" << std::endl;
    }

    delete[] array;
}
