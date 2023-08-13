#include <iostream>

int findDigitSum(int num) {

    if (num <= 0) {
        return 0;
    }

    return num % 10 + findDigitSum(num / 10);
    
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << "Result: " << findDigitSum(n) << std::endl;
}
