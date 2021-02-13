#include <iostream>
#include <math.h>

int main()
{
    int number;
    std::cin >> number;
    int i = 2;
    bool is_prime = true;
    while (i <= sqrt(number) + 1){
        if(number % i == 0){
            is_prime = false;
            break;
        }
        i += 1;
    }
    if (!is_prime){
        std::cout << 0;
    }
    else{std::cout << 1;}
}
