#include <iostream>

int main()
{
    int year;
    std::cin >> year;
    auto cond1 = year % 4;
    auto cond2 = year % 100;
    auto cond3 = year % 400;
    if (cond1 == 0 && cond2 != 0 || cond3 == 0){
        std::cout << "YES";
    }
    else {std::cout << "NO";}
}
