#include <iostream>

int main()
{
    int N, K, num;
    std::cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        std::cin >> num;
        if (num == K)
        {
            std::cout << i + 1;
            return 0;
        }
    }
    std::cout << -1;
}
