#include <iostream>
#include <string>

int main()
{
    std::string car;
    std::string boss = "A999AA";
    int speed;
    int summ = 0;
    int speed_max = 60;
    while(true){
        std::cin >> speed;
        std::cin >> car;
        if(car == boss){
            break;
        }
        if(speed > speed_max){
            if(car[1] == car[2] && car[2]==car[3])
                summ += 1000;
            else if (car[1] == car[2] || car[2] == car[3] || car[1] == car[3])
                summ += 500;
            else
                summ += 100;
        }
    }
    std::cout << summ;
}
