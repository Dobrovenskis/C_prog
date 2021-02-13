#include <iostream>

int main()
{
    int number = 1;
    int bigest = 0;
    int count_bigest = 0;
    while (number != 0){
        std::cin >> number;
        if (bigest < number){
            bigest = number;
            count_bigest = 0;
        }
        if(bigest == number){
            count_bigest += 1;
        }
    }
    std::cout << count_bigest;
}
