#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double point = 1.;
    double summ = 0.;
    double square_summ = 0.;
    double kolvo = -1;
    while (point!=0)
    {
        std::cin >> point;
        kolvo++;
        summ += point;
        square_summ += point*point;
    }
    double D;
    double M;
    M = summ/kolvo;
    D = square_summ/kolvo - M*M;
    //M = std::round(1000*M)/1000;
    //D = std::round(1000*D)/1000;

    //std::cout << std::fixed << std::setprecision(3) << std::round(1000*249500.25)/1000;





    if (int(M) == M )
    {
        std::cout << std::fixed << std::setprecision(1) << M;
    }

    else if (int(10*M) == 10*M)
    {
        std::cout << std::fixed << std::setprecision(1) << M;
    }

    else if (int(100*M) == 100*M)
    {
        std::cout << std::fixed << std::setprecision(2) << M;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(3) << M;
    }


    std::cout << " ";


    if (int(D) == D)
    {
        std::cout << std::fixed << std::setprecision(1) << D;
    }
    else if (int(10*D) == 10*D)
    {
        std::cout << std::fixed << std::setprecision(1) << D;
    }
    else if (int(100*D) == 100*D)
    {
        std::cout << std::fixed << std::setprecision(2) << D;
    }
    else
    {
        std::cout << std::fixed << std::setprecision(3) << D;
    }

    /*
    if (std::abs((float)((int)M)-M) == 0)
    {
//        std::cout <<".0";
    }
    std::cout << " ";
    std::cout <<D;
    if (((float)((int)D)) == D)
    {
//        std::cout <<".0";
    }
    */
}
