# import "C:\Users\1\C++\C_prog\4\List.cpp"

struct Stack{
    List* my_list;
};

Stack* create_stack(List* this_list){
    Stack* my_stack = new Stack();
    my_stack -> my_list = this_list;
    return my_stack;
}

Stack* create_empty_stack(){
    Stack* my_stack = create_stack(create_empty());
    return my_stack;
}

void push(Stack* my_stack, int my_value){
    Add(my_stack -> my_list, my_value);
}

void print_stack(Stack* my_stack){
    print_list(my_stack -> my_list);
}

void pop(Stack* my_stack){
    del_i(my_stack -> my_list,  my_stack -> my_list -> len - 1);
}

int main(){
    Stack* st = create_empty_stack();
    push(st, 0);
    push(st, 1);
    push(st, 2);
    push(st, 3);

    print_stack(st);
    pop(st);
    print_stack(st);
}
