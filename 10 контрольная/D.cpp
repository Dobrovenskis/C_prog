#include <string>
#include <iostream>

int main()
{
    std::string st;
    std::getline(std::cin,st);
    int maxs = 0;
    int n = 0;

    for(int i = 0; i < st.length(); i++)
    {
        if (st[i] != ' ')
        {
            if (st[i] >= 48 & st[i] <= 57)
            {
                n = n*10 + int(st[i] - 48);
            }
            else
            {
                if (maxs < n)
                {
                    maxs = n;
                }
                n = 0;
            }
        }
        else
        {
            if (maxs < n)
                {
                    maxs = n;
                }
                n = 0;
        }
    }
    if (maxs < n)
                {
                    maxs = n;
                }
    std::cout << maxs;

}


