#include <iostream>

void bouble(int mas1[], int mas2[], int n)
{
    int now_el = mas1[0];
    int sled_el;
    int now_el2;
    int sled_el2;
    bool finish = true;
    while(finish)
    {
        finish = false;
        for (int i = 0; i < n - 1; i++)
        {
            now_el = mas1[i];
            sled_el = mas1[i+1];
            now_el2 = mas2[i];
            sled_el2 = mas2[i+1];
            if (sled_el < now_el)
            {
                mas1[i] = sled_el;
                mas1[i+1] = now_el;
                mas2[i] = sled_el2;
                mas2[i+1] = now_el2;
                finish = true;
            }
        }
    }
}


int main()
{
    int N, num;
    std::cin >> N;
    int mas1[N];
    int mas2[N];
    for(int i = 0; i < N; i++)
    {
        std::cin >> num;
        mas1[i] = num;
    }
    for(int i = 0; i < N; i++)
    {
        std::cin >> num;
        mas2[i] = num;
    }
    bouble(mas1, mas2, N);
    for(int i = 0; i < N; i++)
    {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < N; i++)
    {
        std::cout << mas2[i] << " ";
    }
}
