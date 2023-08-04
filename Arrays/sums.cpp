#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int largestSum(int arr[], unsigned size, unsigned m) {
    bubbleSort(arr, size);
    int largestSum = 0;

    for (size_t i = size - 1; i >= size - m; i--) {
        largestSum += arr[i];
    }

    return largestSum;
}

int smallestSum(int arr[], unsigned size, unsigned m) {
    bubbleSort(arr, size);
    int smallestSum = 0;

    for (size_t i = 0; i < m; i++) {
        smallestSum += arr[i];
    }

    return smallestSum;
}


int main()
{
    unsigned n, m;

    std::cout << "Enter a 'n' - size of array: ";
    std::cin >> n;
    std::cout << std::endl;

    std::cout << "Enter a 'm' - number of elements to sum: ";
    std::cin >> m;
    std::cout << std::endl;

    int* array = new int[n];

    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    std::cout << "Largest sum is " << largestSum(array, n, m) << std::endl;
    std::cout << "Smallest sum is " << smallestSum(array, n, m) << std::endl;

    delete[] array;
}
