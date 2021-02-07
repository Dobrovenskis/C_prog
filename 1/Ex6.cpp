#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    for (int i = N; i>=1; i -= 2){
        int n_prob;
        n_prob = (N - i)/2;
        for (int m = 1; m <= n_prob; m++) {
            std::cout << " ";
        }
        for (int k = 1; k <= i; k++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
