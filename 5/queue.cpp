# import "C:\Users\1\C++\C_prog\4\List.cpp"

struct Queue{
    List* my_list;
};

Queue* create_queue(List* this_list){
    Queue* my_queue = new Queue();
    my_queue -> my_list = this_list;
    return my_queue;
}

Queue* create_empty_queue(){
    Queue* my_queue = create_queue(create_empty());
    return my_queue;
}

void add_queue(Queue* my_queue, int my_value){
    add_to_begin(my_queue -> my_list, my_value);
}

void print_queue(Queue* my_queue){
    print_list(my_queue -> my_list);
}

void pop_queue(Queue* my_queue){
    del_i(my_queue -> my_list,  my_queue -> my_list -> len - 1);
}

int main(){
    Queue* que = create_empty_queue();
    add_queue(que, 0);
    add_queue(que, 1);
    add_queue(que, 2);
    add_queue(que, 3);

    print_queue(que);
    pop_queue(que);
    print_queue(que);
}
