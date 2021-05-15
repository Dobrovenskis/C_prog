#include <iostream>
#include <vector>

void print_mas(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bouble(float mas[], int n)
{
    float now_el = mas[0];
    float sled_el;
    bool finish = true;
    while(finish)
    {
        finish = false;
        for (int i = 0; i < n - 1; i++)
        {
            now_el = mas[i];
            sled_el = mas[i+1];
            if (sled_el < now_el)
            {
                mas[i] = sled_el;
                mas[i+1] = now_el;
                finish = true;
            }
            //else
            //{
            //    now_el = sled_el;
            //}
        }
    }
}

void shaker(float mas[], int n)
{
    float now_el = mas[0];
    float sled_el;
    bool finish = true;
    while(finish)
    {
        finish = false;
        for (int i = 0; i < n - 1; i++)
        {
            now_el = mas[i];
            sled_el = mas[i+1];
            if (sled_el < now_el)
            {
                mas[i] = sled_el;
                mas[i+1] = now_el;
                finish = true;
            }
        }
        for (int i = n-1; i > 0; i--)
        {
            now_el = mas[i];
            sled_el = mas[i-1];
            if (sled_el > now_el)
            {
                mas[i] = sled_el;
                mas[i-1] = now_el;
                finish = true;
            }
        }
    }
}

void insertion(float mas[], int n)
{
    float now_el;
    bool finish = true;
    for(int i = 0; i < n; i++)
    {
        now_el = mas[i];
        finish = true;
        for(int k = i; k > 0 && finish; k--)
        {
            if (mas[k-1] > now_el)
            {
                mas[k] = mas[k-1];
                mas[k-1] = now_el;
            }
            else
            {
                finish = false;
            }
        }
    }
}

void shell_del_2(float mas[], int n)
{
    int d = n/2;
    float now_el;
    bool finish = true;
    for (d; d != 0; d /= 2)
    {
        for(int i = d; i < n; i++)
        {
            now_el = mas[i];
            int m;

            for (m = i; m >= d && mas[m - d] > now_el; m -= d)
            {
                mas[m] = mas[m - d];
            }
            mas[m] = now_el;
        }
    }
}

void merge_sort(float mas[], int n)
{
    if (n > 1)
    {
        int left_size = n/2;
        float left[left_size];
        int right_size = n - n/2;
        float right[right_size];
        for (int i = 0; i < left_size; i++)
        {
            left[i] = mas[i];
        }
        for (int i = left_size; i < n; i++)
        {
            right[i - left_size] = mas[i];
        }

        merge_sort(left, left_size);
        merge_sort(right, right_size);

        int i, j, m;
        i = 0;
        j = 0;
        m = 0;

        for(m; i < left_size && j < right_size; m++)
        {
            if (left[i] < right[j])
            {
                mas[m] = left[i];
                i ++;
            }
            else
            {
                mas[m] = right[j];
                j ++;
            }
        }

        while (i < left_size)
        {
            mas[m] = left[i];
            m ++;
            i ++;
        }
        while(j < right_size)
        {
            mas[m] = right[j];
            j++;
            m++;
        }
    }
}


void seletion(float mas[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int room_min = i;
        for (int t = i + 1; t < n; t++)
        {
            if (mas[t] < mas[room_min])
            {
                room_min = t;
            }
        }

        int min_value = mas[room_min];
        //for(int t = room_min; t>n; t++)
        //{
        //    mas[]
        //}
        mas[room_min] = mas[i];
        mas[i] = min_value;
    }
}

void Qsort(std::vector<float>& mas)
{
    int n = mas.size();
    if (n > 1)
    {
        std::vector<float> left;
        std::vector<float> right;
        std::vector<float> equal_m;


        float begin_n = mas[0];
        for (int i = 0; i < n; i++)
        {
            if (mas[i] < begin_n)
            {
                left.push_back(mas[i]);
            }
            else if (mas[i] > begin_n)
            {
                right.push_back(mas[i]);
            }
            else if (mas[i] == begin_n)
            {
                equal_m.push_back(mas[i]);
            }
        }
        Qsort(left);
        Qsort(right);

        for (int i = 0; i < left.size(); i++)
        {
            mas[i] = left[i];
        }
        for (int i = 0; i < equal_m.size(); i++)
        {
            mas[i + left.size()] = equal_m[i];
        }
        for (int i = 0; i < right.size(); i++)
        {
            mas[i + equal_m.size() + left.size()] = right[i];
        }


    }

}

void qsort_(float mas[], int n)
{
    std::vector<float> mas_new(n);
    for (int i = 0; i < n; i++)
    {
        mas_new[i] = mas[i];
    }

    Qsort(mas_new);

    for (int i = 0; i < n; i++)
    {
        mas[i] = mas_new[i];
    }
}




int main()
{
    int n;
    std:: cin >> n;
    float a;
    float mas[n];
    for(int k = 0; k < n; k++)
        {
            std::cin >> a;
            mas[k] = a;
        }
    //bouble(mas, n);

    //shaker(mas, n);

    //insertion(mas, n);

    //shell_del_2(mas, n);// ???

    //seletion(mas,n);

    //merge_sort(mas, n); // ??

    qsort_(mas,n);

    print_mas(mas, n);


}
