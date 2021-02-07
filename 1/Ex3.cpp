#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int i = 1; i <= N; i++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
