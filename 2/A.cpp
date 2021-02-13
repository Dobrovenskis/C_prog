#include <iostream>

int main()
{
    int numerator;
    std::cin >> numerator;
    int denominator;
    std::cin >> denominator;
    int r;
    int ost;
    while (denominator != 0) {
        ost = numerator % denominator;
        numerator = denominator;
        denominator = ost;
    }
    std::cout << numerator;
}
