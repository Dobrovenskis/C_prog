#include <iostream>

int main()
{
    int number = 1;
    int bigest = 0;
    while (number != 0){
        std::cin >> number;
        if (number %2 == 0 && number != 0){
            if (bigest < number){
                bigest = number;
            }
        }
    }
    std::cout << bigest;
}
