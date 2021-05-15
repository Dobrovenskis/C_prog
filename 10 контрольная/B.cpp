#include <string>
#include <iostream>

int main()
{
    std::string st;
    int sum = 0;
    std::cin >> st;
    std::getline(std::cin,st);

    for(int i = 0; i < st.length(); i++)
    {
        if (st[i] == ' ')
        {
            sum += 1;
        }
    }
    std::cout << sum + 1;

}

