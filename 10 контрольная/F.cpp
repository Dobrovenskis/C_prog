#include <iostream>

int main()
{
    int n, tn, tn1,tn2;
    int x;
    std::cin >> x;
    n = 0;
    int t0 = 0;
    int t1 = 0;
    int t2 = 1;
    int tn3;
    tn = t0;
    tn1 = t1;
    tn2 = t2;
    if (x < t0)
    {
        std::cout << 0;
        return 0;
    }
    if (x < t2)
    {
        std::cout << 2;
        return 0;
    }
    while (tn2 <= x)
    {
        n ++;
        tn3 = tn2 + tn1 + tn;
        tn = tn1;
        tn1 = tn2;
        tn2 = tn3;
    }

    std::cout << n + 2;

}
