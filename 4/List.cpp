#include <iostream>
#include <clocale>

struct field_List{
    int value;
    field_List *next;
};

struct List{
    field_List *field_begin;
    field_List *field_end;
    int len;
};

List* create_begin(int this_value){
    field_List *my_field_begin = new field_List();
    my_field_begin -> value = this_value;
    my_field_begin -> next = nullptr;

    List *o_List = new List();
    o_List -> field_begin = my_field_begin;
    o_List -> field_end = my_field_begin;
    o_List -> len = 1;
    return o_List;
}

void Add(List* my_list, int my_value){
    if (my_list -> len == 0){
        field_List *my_field_begin = new field_List();
        my_field_begin -> value = my_value;
        my_field_begin -> next = nullptr;

        my_list -> field_begin = my_field_begin;
        my_list -> field_end = my_field_begin;
        my_list -> len = 1;
        return;
    }
    field_List *new_field_end = new field_List();
    new_field_end -> value = my_value;
    my_list -> field_end -> next = new_field_end;
    my_list -> len ++;
    new_field_end -> next = nullptr;
    my_list -> field_end = new_field_end;
}

void add_to_begin(List* my_list, int my_value){
    field_List *new_field_begin = new field_List();
    new_field_begin -> value = my_value;
    my_list -> len ++;
    new_field_begin -> next = my_list -> field_begin;
    my_list -> field_begin = new_field_begin;
}



void print_list(List* my_List){
    field_List *my_field = my_List -> field_begin;
    int len = my_List -> len;
    for (int i = 0; i < len; i++){
        std::cout << my_field -> value << " ";
        my_field = my_field -> next;
    }
    std::cout << std::endl;
}

void remove_my(List* my_list, int del){
    field_List *field = my_list -> field_begin;
    field_List *field_before = my_list -> field_begin;
    bool finish = false;
    if (my_list -> field_begin -> value == del){
        my_list -> field_begin = my_list -> field_begin -> next;
        my_list -> len--;
        return;
    }
    for (int i = 0; i < my_list -> len; i++){
        field = field ->next;
        if (field -> value == del){
            field_before -> next = field -> next;
            finish = true;
            delete[] field;
            my_list -> len--;
            break;
        }
        field_before = field_before -> next;
    }
    if (!finish){
        std::cout << "Такого элемента нет" << std::endl;
    }
}

List* copy_list(List* my_list){
    List* cop_list = create_begin(my_list -> field_begin -> value);
    field_List* field = my_list -> field_begin;
    for (int i = 1; i < my_list -> len; i++){
        field = field -> next;
        Add(cop_list, field -> value);
    }
    return cop_list;
}

List* revers(List* my_list){
    List* revers_list = new List();
    int masiv_value_my_list[my_list -> len];
    int masiv_value_revers_list[my_list -> len];
    field_List* field = my_list -> field_begin;

    for (int i = 0; i <  my_list -> len; i++){
        masiv_value_my_list[i] = field -> value;
        field = field -> next;
    }

    for (int i = 0; i < my_list -> len; i++ ){
        masiv_value_revers_list[i] = masiv_value_my_list[(my_list -> len) - 1 - i];
    }

    revers_list = create_begin(masiv_value_revers_list[0]);
    for (int i = 1; i < my_list -> len; i++){
        Add(revers_list,masiv_value_revers_list[i]);
    }

    return revers_list;
}

List* merge_list(List* first_list, List* second_list){
    List* new_list = copy_list(first_list);
    field_List* field = second_list -> field_begin;

    for (int i = 0; i < second_list -> len; i++){
        Add(new_list, field -> value);
        field = field -> next;
    }
    return new_list;
}

void add_i(List* my_list, int val_add, int i){
    if (i > my_list -> len){
        std::cout << "Это больше длины списка" << std::endl;
        return;
    }

    if (i == 0){
        add_to_begin(my_list, val_add);
        return;
    }

    if (i == my_list->len){
        Add(my_list, val_add);
        return;
    }

    field_List* field;
    field_List *new_field = new field_List();
    new_field -> value = val_add;

    field = my_list -> field_begin;
    for (int k = 0; k < i - 1; k++){
        field = field -> next;
    }
    new_field -> next = field -> next;
    field -> next = new_field;

    my_list -> len++;
}

void del_i(List* my_list, int i){
    field_List* field;
    if (i > my_list -> len - 1){
        std::cout << "Это больше длины списка" << std::endl;
        return;
    }
    if (i==0){
        remove_my(my_list, my_list -> field_begin -> value);
        return;
    }
    field = my_list -> field_begin;

    for (int k = 0; k < i - 1; k++){
        field = field -> next;
    }
    field_List* field_del = field -> next;
    field -> next = field_del -> next;
    delete[] field_del;

    my_list -> len--;
}

void del_list(List* my_list){
    field_List* field;
    field_List* field_new;
    field = my_list -> field_begin;
    for (int k = 0; k < my_list -> len - 1; k++){
        field_new = field -> next;
        delete[] field;
        field = field_new;
    }
}

List* create_empty(){
    List *o_List = new List();
    o_List -> field_begin = nullptr;
    o_List -> field_end = nullptr;
    o_List -> len = 0;
    return o_List;
}
/*
int main(){
    setlocale(LC_ALL,"Russian");

    List *masiv = new List();
    int zn_mas[5] = {1, 2, 3, 4, 5};
    masiv = create_begin(zn_mas[0]);
    for (int i = 1; i < 5; i++){
        Add(masiv,zn_mas[i]);
    }
    List* emp = create_empty();
    Add(emp, 130);
    print_list(emp);

    remove_my(masiv, 1);
    remove_my(masiv, 3);
    print_list(masiv);

    add_to_begin(masiv, 0);
    print_list(masiv);

    List* cop_masiv = copy_list(masiv);
    print_list(cop_masiv);

    List* revers_masiv = revers(cop_masiv);
    print_list(revers_masiv);

    List* merge_masiv = merge_list(revers_masiv, masiv);
    print_list(merge_masiv);

    add_i(masiv, 30, 3);
    print_list(masiv);

    del_i(masiv, 3);
    print_list(masiv);
}*/
