#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>


float** create_empty(int n)
{
    float** mat_1 = new float*[n];
    for (int i = 0; i < n; i++)
        {
            mat_1[i] = new float[n];
            for(int k = 0; k < n; k++)
            {
                mat_1[i][k] = 0;
            }
    }
    return mat_1;
}

float** create_mas(int n)
{
    float** mat_1 = create_empty(n);

    for (int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                float a;
                std::cin >> a;
                mat_1[i][k] = a;
            }
    }
    return mat_1;
}

float** create_random(int n)
{
    float** mat_1 = create_empty(n);

    for (int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                int a;
                a = rand() % 2;
                mat_1[i][k] = float(a);
            }
    }
    return mat_1;
}

float** multiplication(float** mat_1, float** mat_2, int n)
{
    float** mat_pr = new float*[n];
    float sum;
    for (int i = 0; i < n; i++)
        {
            mat_pr[i] = new float[n];
            for(int k = 0; k < n; k++)
            {
                sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += mat_1[i][j]*mat_2[j][k];
                }
                mat_pr[i][k] = sum;
            }
        }
    return mat_pr;
}

float** sum(float** mat_1, float** mat_2, int n)
{
    float** mat_sum = create_empty(n);
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            mat_sum[i][k] = mat_1[i][k] + mat_2[i][k];
        }
    }
    return mat_sum;
}

float** minus_(float** mat_1, float** mat_2, int n)
{
    float** mat_sum = create_empty(n);
    for(int i = 0; i < n; i++)
    {
        for(int k = 0; k < n; k++)
        {
            mat_sum[i][k] = mat_1[i][k] - mat_2[i][k];
        }
    }
    return mat_sum;
}


void print_mat(float** mat, int size_m)
{
    for (int i = 0; i < size_m; i++)
    {
        for (int k = 0; k < size_m; k++)
        {
            std::cout << mat[i][k] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

float** strassen(float** A_st, float** B_st, int n)
{
    float** C_new;
    if (n < 64)
    {
        C_new = multiplication(A_st, B_st, n);
    }

    else
    {

        int step_2;
        step_2 = log(n)/log(2);
        if (pow(2,step_2) != n)
        {
            step_2 += 1;
        }
        int n_new = pow(2,step_2);

        C_new = create_empty(n);

        float** A = create_empty(n_new);
        float** B = create_empty(n_new);
        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                A[i][k] = A_st[i][k];
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int k = 0; k < n; k++)
            {
                B[i][k] = B_st[i][k];
            }
        }


        int n_del = n_new/2;

        float** A11 = create_empty(n_del);
        float** A12 = create_empty(n_del);
        float** A21 = create_empty(n_del);
        float** A22 = create_empty(n_del);
        float** B11 = create_empty(n_del);
        float** B12 = create_empty(n_del);
        float** B21 = create_empty(n_del);
        float** B22 = create_empty(n_del);

        for (int i = 0; i < n_del; i++)
        {
            for (int k = 0; k < n_del; k++)
            {
               A11[i][k] = A[i][k];
               A12[i][k] = A[i][k + n_del];
               A21[i][k] = A[i + n_del][k];
               A22[i][k] = A[i + n_del][k + n_del];

               B11[i][k] = B[i][k];
               B12[i][k] = B[i][k + n_del];
               B21[i][k] = B[i + n_del][k];
               B22[i][k] = B[i + n_del][k + n_del];
            }
        }

        float** P1 = strassen(sum(A11, A22, n_del), sum(B11, B22, n_del), n_del);
        float** P2 = strassen(sum(A21, A22, n_del), B11, n_del);
        float** P3 = strassen(A11, minus_(B12, B22, n_del), n_del);
        float** P4 = strassen(A22, minus_(B21, B11, n_del),n_del);
        float** P5 = strassen(sum(A11, A12, n_del), B22,n_del);
        float** P6 = strassen(minus_(A21, A11, n_del), sum(B11, B12, n_del),n_del);
        float** P7 = strassen(minus_(A12, A22, n_del), sum(B21, B22, n_del),n_del);


        float** C11 = minus_(sum(sum(P1, P4, n_del), P7, n_del),P5, n_del);
        float** C12 = sum(P3, P5, n_del);
        float** C21 = sum(P2, P4, n_del);
        float** C22 = minus_(sum(sum(P1, P3, n_del), P6, n_del),P2, n_del);

        float ** C = create_empty(n_new);

        for(int i=0; i<n_del; i++)
        {
            for(int k=0; k<n_del; k++)
            {
                C[i][k] = C11[i][k];
                C[i][k+n_del] = C12[i][k];
                C[i+n_del][k] = C21[i][k];
                C[i+n_del][k+n_del] = C22[i][k];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int k=0; k<n; k++)
            {
                C_new[i][k] = C[i][k];
            }
        }

        for(int i=0; i<n_del; i++)
        {
            delete[] A11[i];
            delete[] A12[i];
            delete[] A21[i];
            delete[] A22[i];

            delete[] B11[i];
            delete[] B12[i];
            delete[] B21[i];
            delete[] B22[i];

            delete[] P1[i];
            delete[] P2[i];
            delete[] P3[i];
            delete[] P4[i];
            delete[] P5[i];
            delete[] P6[i];
            delete[] P7[i];

            delete[] C11[i];
            delete[] C12[i];
            delete[] C21[i];
            delete[] C22[i];
        }

        for (int i = 0; i < n_new; i++)
        {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A11;
        delete[] A12;
        delete[] A21;
        delete[] A22;
        delete[] A;
        delete[] B11;
        delete[] B12;
        delete[] B21;
        delete[] B22;
        delete[] B;
        delete[] P1;
        delete[] P2;
        delete[] P3;
        delete[] P4;
        delete[] P5;
        delete[] P6;
        delete[] P7;
        delete[] C11;
        delete[] C12;
        delete[] C21;
        delete[] C22;
        delete[] C;
    }
	return C_new;
}


int main()
{
    int size_m;

    //Умножение заданных квадратных матриц (сначала ввести размер):
    std::cin >> size_m;
    float** mat_1 = create_mas(size_m);
    float** mat_2 = create_mas(size_m);
    float** mat_pr_simple = multiplication(mat_1, mat_2, size_m);
    float** mat_pr_str = strassen(mat_1, mat_2, size_m);
    print_mat(mat_pr_simple, size_m);
    print_mat(mat_pr_str, size_m);

    // Следующий код для измерения времени работы простого умножения.
    for (int i = 64; i < pow(2,0); i *=2)
    {
        size_m = i;

        float** mat_1 = create_random(size_m);
        float** mat_2 = create_random(size_m);

        float** mat_pr;

        auto start_simple = std::chrono::steady_clock::now();
        mat_pr = multiplication(mat_1, mat_2, size_m);
        auto end_time_simple = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff_simple = end_time_simple - start_simple;


        std::ofstream out("C:\\Users\\1\\C++\\C_prog\\6\\time_simple_2.txt", std::ios::app);
        if (out.is_open())
        {
            out << "{" <<size_m <<"," << diff_simple.count() << "};";
        }
        out.close();

    }

    //Следующий код для измерения времени работы алгоритма штрассена
    for (int i = 64; i < pow(2,0); i *=2)
    {
        size_m = i;
        float** mat_1 = create_random(size_m);
        float** mat_2 = create_random(size_m);

        float** mat_pr;

        auto start_simple = std::chrono::steady_clock::now();
        mat_pr = strassen(mat_1, mat_2, size_m);
        auto end_time_simple = std::chrono::steady_clock::now();
        std::chrono::duration<double> diff_simple = end_time_simple - start_simple;


        std::ofstream out("C:\\Users\\1\\C++\\C_prog\\6\\time_strassen.txt", std::ios::app);
        if (out.is_open())
        {
            out << "{" <<size_m <<"," << diff_simple.count() << "};";
        }
        out.close();

    }

}

