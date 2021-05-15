# import "C:\Users\1\C++\C_prog\4\List.cpp"
# include <chrono>

int main()
{

    for(int k = 0; k < 1000; k ++)
    {
        int n = 1 + k*10;
        List* list_1 = create_empty();
        for (int i = 0; i < n; i++){
            Add(list_1, i);
        }

        auto start = std::chrono::steady_clock::now();
        //Add(list_1, 5);
        del_i(list_1,  list_1 -> len - 1);
        auto end_time = std::chrono::steady_clock::now();
        del_list(list_1);

        std::chrono::duration<double> diff = end_time - start;
        std::cout << "Time " << n << " = " << diff.count() << std::endl;
    }
}
