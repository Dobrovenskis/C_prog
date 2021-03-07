#include <iostream>
# import "C:\Users\1\C++\C_prog\4\List.cpp"
# import "C:\Users\1\C++\C_prog\3\F_change_memory.cpp" //Функция, которая меняет количество памяти выделенной под массив
//int length_start_masiv = 3;

struct Stack_masiv{
    int* masiv;
    int length;
};

Stack_masiv* create_empty_stack_masiv(){
    Stack_masiv* my_stack = new Stack_masiv;
    int *arr = new int[0];
    my_stack -> masiv = arr;
    my_stack -> length = 0;
    return my_stack;
}

void push_in_strack_masiv(Stack_masiv *this_stack, int value){
    int* arr = my_slightly_dumb_reallocation(this_stack -> masiv, this_stack -> length, ++(this_stack -> length));
    this_stack -> length = this_stack -> length ++;
    arr[this_stack -> length - 1] = value;
    this_stack -> masiv = arr;
}

void pop_stack_masiv_element(Stack_masiv *this_stack){
    int* arr = my_slightly_dumb_reallocation(this_stack -> masiv, this_stack -> length, this_stack -> length --);
    this_stack -> length = this_stack -> length --;
    this_stack -> masiv = arr;
}

void print_stack_masiv(Stack_masiv *this_stack){
    for (int i = 0; i < this_stack -> length; i++)
		std::cout << (this_stack -> masiv)[i];
     std::cout << std::endl;
}

int main(){
    Stack_masiv* st = create_empty_stack_masiv();
    push_in_strack_masiv(st, 0);
    push_in_strack_masiv(st, 1);
    push_in_strack_masiv(st, 2);
    push_in_strack_masiv(st, 3);

    print_stack_masiv(st);
    pop_stack_masiv_element(st);
    print_stack_masiv(st);
}
