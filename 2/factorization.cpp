#include <iostream>
#include <math.h>

int main()
{
    int number;
    int i = 2;
    bool is_prime = false;
    std::cin >> number;
    while(!is_prime){
        is_prime = true;
        while (i <= sqrt(number) + 1){
            if(number % i == 0){
                std::cout << i << std::endl;
                is_prime = false;
                break;
            }
            i += 1;
        }
        if(is_prime){
            std::cout << number;
            break;
        }
        number = number/i;
    }
}
