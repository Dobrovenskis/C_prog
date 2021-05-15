#include <string>
#include <iostream>

int main()
{
    std::string st;
    std::getline(std::cin,st);
    int a = -1;

    for(int i = 0; i < st.length(); i++)
    {
        if (st[i] != ' ')
        {
            if (a == 1)
            {
                if (st[i] < 97)
                {
                    st[i] = st[i] + 32;
                }
            }
            else
            {
                if (st[i] >= 97)
                {
                    st[i] = st[i] - 32;
                }
            }
            a *= -1;
        }
    }
    std::cout << st;

}

