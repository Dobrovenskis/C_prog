#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = N; i>=1; i--){
        for (int k = 1; k <= i; k++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
