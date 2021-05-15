#include <iostream>

struct Ab
{
    char name[50];
    long long telephone;
    int money;
};

int main()
{
    int n;
    std::cin >> n;
    Ab* abon = new Ab[n];
    for(int i = 0; i < n; i++)
    {
        //char nam;
        //int tel;
        //int mon;

        /*std::cin >> nam >> tel >> mon;
        abon[i].name = nam;
        abon[i].telephone = tel;
        abon[i].money = mon;*/
        std:: cin >> abon[i].name >> abon[i].telephone >> abon[i].money;
    }

    Ab sort_;

    for (int i=0;i<n-1;i++)
    {
        for (int g=i+1;g<n;g++)
        {
            if(abon[i].money>abon[g].money)
            {
            sort_=abon[i];
            abon[i]=abon[g];
            abon[g]=sort_;
            }
        }
    }

    int dolgniki = 0;
    for (int i =0; i < n; i++)
    {
        if (abon[i].money < 0)
        {
            dolgniki ++;
        }
    }

    if (dolgniki < 100)
    {
        for(int i = 0; i < dolgniki; i++)
        {
            std::cout << abon[i].name << " " << abon[i].telephone << " " << abon[i].money << std:: endl;

        }
    }
    else
    {
       for(int i = 0; i < 100; i++)
        {
            std::cout << abon[i].name << " " << abon[i].telephone << " " << abon[i].money << std:: endl;

        }
    }
}

