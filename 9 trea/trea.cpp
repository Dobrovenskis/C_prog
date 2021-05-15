# include <iostream>


struct Node
{
    int value;
    Node *right;
    Node *left;
    Node *up;
    int height;
};

struct Tre
{
    Node *begin_node;
    int amount_node;
};

Tre* create_begin(int my_value)
{
    Tre *tre = new Tre();
    Node *my_begin_node = new Node();
    tre -> begin_node = my_begin_node;
    tre -> begin_node->value = my_value;
    tre -> amount_node = 1;
    tre -> begin_node -> height = 0;
    return tre;
}

void recalculate_height(Node* node, int n_height)
{
    n_height ++;
    if (node -> up != nullptr && node -> height < n_height)
    {
        node -> up -> height = n_height;
        recalculate_height(node->up, n_height);
    }
}

void add_with_direction(Tre* tre, int my_val, Node* parent, int direction)
{

    Node *node = new Node();

    if (tre->amount_node == 0)
    {
        tre -> begin_node = node;
        node ->value = my_val;
    }

    else
    {
        node ->value = my_val;
        node -> up = parent;
        node -> height = 0;
        if (direction == 2)
        {
            parent -> right = node;
        }
        if (direction == 1)
        {
            parent -> left= node;
        }
        tre ->amount_node ++;
        recalculate_height(node, 0);
    }

}

void add(Tre* tre, int my_val, Node* parent)
{
    if (parent->left == nullptr)
    {
        add_with_direction(tre, my_val, parent, 1);
    }
    else if (parent->right == nullptr && my_val >= parent->left->value)
    {
        add_with_direction(tre, my_val,parent,2);
    }
    else if (parent -> right == nullptr && my_val < parent->left->value)
    {
        parent->right = parent -> left;
        add_with_direction(tre, my_val, parent, 1);
    }
}

void add2(Tre* tre, int my_value, Node* node)
{
    if (my_value <= node -> value)
    {
        if (node->left == nullptr)
        {
            add_with_direction(tre, my_value, node, 1);
        }
        else
        {
            add2(tre, my_value, node->left);
        }
    }
    else if (my_value > node->value)
    {
        if (node->right == nullptr)
        {
            add_with_direction(tre, my_value, node, 2);
        }
        else
        {
            add2(tre, my_value, node->right);
        }
    }
    else
    {
        std::cout << "It is strange";
    }
}

void add3(Tre* tre, int value)
{
    add2(tre, value, tre->begin_node);
}

void rewrite_value(Tre* tre, int my_val, Node* this_node)
{
    this_node -> value = my_val;
}

/*void pre_order(Tre* tre)
{
    bool finish = true;
    now_node = tre->begin_node;
    for (int i = 0; i < tre->amount_node; i++)
    {
        while (now_node->left != nullptr)
        {
            now_node = now_node->left;
            std::cout << now_node -> value;
        }
        else
        {
            if (no)
            now_node = now_node -> up;
        }
    }
}*/

int count_height(Tre* tre)
{
    return tre->begin_node->height;
}

void r_rotation(Tre* tre, Node* versh)
{

}


int main()
{
    Tre *tre = new Tre();
    tre = create_begin(5);
    //rewrite_value(tre, 3, tre->begin_node);
    //add(tre, 5, tre->begin_node);
    //add(tre, 5, tre->begin_node);
    //add(tre, 6, tre->begin_node->right);
    //add(tre, 7, tre->begin_node->right->left);
    int mas[6] = {6,7,8,9,10,11};
    for (int i = 0; i < 6; i++)
    {
        add3(tre,mas[i]);
    }
    std::cout << count_height(tre);
}
