#include <iostream>
#include <math.h>

int main()
{
    int number;
    std::cin >> number;
    int i = 1;
    int numeral;
    int rank_my = 60;
    bool cond = false;
    float chislo;
    while(number > 0){
        if(number / i < rank_my){
            numeral = number / i;
            for (int k = 1; k <= numeral/10; k++){
                std::cout << "<";
            }
            for (int k = 1; k <= numeral%10; k++){
                std::cout << "v";
            }
            if (number%i == 0){
                chislo = log(i)/log(rank_my) + 1;
            }
            else{chislo = - log(number%i)/log(rank_my) + log(i)/log(rank_my) + 1;}
            if (number >= rank_my){
                for(int k = 1; k < chislo; k++){
                    std::cout << ".";
                }
            }
            number %= i;
            i = 1;
            cond = true;
        }
        if (!cond){
            i*=rank_my;
        }
        cond = false;
    }
}
