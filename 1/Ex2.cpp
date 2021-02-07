#include <iostream>
#include <math.h>

int main()
{
    int x;
    int y;
    std::cin >> x;
    std::cin >> y;
    auto z = sqrt(x*x + y*y);
    std::cout << z << std::endl;
    return 0;
}
