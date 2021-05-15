#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int numb;
    bool flag = true;
    for (int i = 0; i<N; i++)
    {
        std::cin >> numb;
        if (numb % 4 == 0 && numb/1000!=4 && numb/1000!=5 )
        {
            std::cout << numb << std::endl;
            flag = false;
        }
        else if (numb % 7 == 0 && numb/1000!=7 && numb/1000!=1 )
        {
            std::cout << numb << std::endl;
            flag = false;
        }
        else if (numb % 9 == 0 && numb/1000!=9 && numb/1000!=8 )
        {
            std::cout << numb << std::endl;
            flag = false;
        }
    }
    if (flag)
    {
        std::cout << 0;
    }
}
