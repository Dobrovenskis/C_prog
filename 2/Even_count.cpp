#include <iostream>

int main()
{
    int number = 1;
    int count_even = 0;
    while (number != 0){
        std::cin >> number;
        if (number %2 == 0 && number != 0){
            count_even += 1;
        }
    }
    std::cout << count_even;
}
