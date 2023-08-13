#include <iostream>

int binarySearch(int array[], int number, int left, int right) {
    if (left > right) {
        return -1; 
    }

    int mid = (left + right) / 2;

    if (array[mid] == number) {
        return mid;
    }
    else if (array[mid] < number) {
        return binarySearch(array, number, mid + 1, right);
    }
    else {
        return binarySearch(array, number, left, mid - 1);
    }
}

int main()
{
    int array[] = { 1, 5, 6, 7, 12, 16, 19, 22, 33, 43, 56, 58 };
    int number;
    std::cin >> number;
    std::cout << "Found " << number << " at index " << binarySearch(array, number, 0, 11);
}
