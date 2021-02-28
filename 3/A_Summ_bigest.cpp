#include <iostream>

int main()
{
    int n;
    int summ = 0;
    int answer = 0;
    std::cin >> n;
    int *arr =  new int[n];

    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++){
        summ += arr[i];
    }
    float sred = summ/n;
    for (int i = 0; i < n; i++){
        if (arr[i] > sred) {
            answer += arr[i];
        }
    }
    std::cout << answer;
    delete[] arr;
    return 0;
}
