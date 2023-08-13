#include <iostream>

int recursionSum(int n, int startVal, int k) {

    if (startVal > n)
    {
        return 0;
    }

    return (startVal + recursionSum(n, startVal + k, k));
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << "Result: " << recursionSum(n, 1, k) << std::endl;
}
