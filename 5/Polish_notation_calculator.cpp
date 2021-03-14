# import "C:\Users\1\C++\C_prog\5\Stack_masiv.cpp"

int main()
{
    Stack_masiv* st = create_empty_stack_masiv();
    char simv;
    //std::cin >> simv;
    while(true){
        std::cin >> simv;
        switch (simv) {
            case '+':
                st->masiv[st->length - 2] += st->masiv[st->length - 1];
                pop_stack_masiv_element(st);
                break;
            case '-':
                st->masiv[st->length - 2] -= st->masiv[st->length - 1];
                pop_stack_masiv_element(st);
                break;
            case '*':
                st->masiv[st->length - 2] *= st->masiv[st->length - 1];
                pop_stack_masiv_element(st);
                break;
            case '/':
                st->masiv[st->length - 2] /= st->masiv[st->length - 1];
                pop_stack_masiv_element(st);
                break;
            case ' ':
                break;
            case '=':
                std::cout << "Result = ";
                print_stack_masiv(st);
                pop_stack_masiv_element(st);
                break;
            default:
                push_in_strack_masiv(st, (int)simv - (int)'0');
                break;
        }
    }
}
