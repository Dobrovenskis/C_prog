#include <iostream>

int main()
{
    int N, num;
    std::cin >> N;
    int mas[N];
    for(int i = 0; i < N; i++)
    {
        std::cin >> num;
        mas[i] = num;
    }
    for(int i = N-1; i >= 0; i--)
    {
        std::cout << mas[i] << " ";
    }
}
