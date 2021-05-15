#include <iostream>

int main()
{
    int n, Sum;
    std::cin >> n;
    Sum = n / 100 + n % 10 + n / 10 % 10;
    std::cout << Sum;
}
