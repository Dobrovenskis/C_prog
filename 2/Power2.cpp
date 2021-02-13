#include <iostream>

int main()
{
    int N;
    int answer = 1;
    std::cin >> N;
    while (N != 1){
        int cond = N % 2;
        N /= 2;
        if (cond == 1){
            answer = 0;
            break;
        }
    }
    if (answer == 0) {
    std::cout << "NO";
    }
    else {
    std::cout << "YES";
    }
}
