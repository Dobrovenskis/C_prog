#include <iostream>
#include <stdio.h>
#include <stdint.h>

void rec(int n, double Fpred)
{
    double M, F;
    M = 0.3 * (100 + 2*Fpred) + 10;
    F = 0.7 * (100 + 2*Fpred);
    if (n > 0)
    {
        n--;
        rec(n, F);
    }
    else
    {
        std::cout << static_cast<int64_t>(M);
    }
}

int main()
{
    int N;
    std::cin >> N;
    rec(N-1, 0);
}
