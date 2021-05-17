# include <iostream>
# include <vector>


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

void preorder(Node* n)
{
   std::cout << n -> value << " ";

   if (n->right != nullptr)
   {
       preorder(n->right);
   }
   if (n->left != nullptr)
   {
       preorder(n->left);
   }
}

void postorder(Node* n)
{
   if (n->right != nullptr)
   {
       postorder(n->right);
   }
   if (n->left != nullptr)
   {
       postorder(n->left);
   }

   std::cout << n -> value << " ";
}

void inforder(Node* n)
{
   if (n->right != nullptr)
   {
       inforder(n->right);
   }

    std::cout << n -> value << " ";


   if (n->left != nullptr)
   {
       inforder(n->left);
   }

}

Node* Find(int val, Node* node_now)
{
    if(node_now == nullptr)
     {
         std::cout << "Nothing found" << std::endl;
     }

    else if(val == node_now->value)
    {
        node_now = node_now;
    }

     else if(val > node_now -> value)
     {
         node_now = Find(val, node_now->right);
     }
     else if(val < node_now -> value)
     {
         node_now = Find(val, node_now->left);
     }

    return node_now;

}



void Delete_value( Tre* tree,int val)
{
    Node* del = Find(val, tree -> begin_node);

    if (del == nullptr)
    {
        return;
    }
    if (del == tree->begin_node)
    {
        if (del->right != nullptr)
        {
            del = Find(val, del->right);
            if (del == nullptr)
            {
                del = Find(val, tree->begin_node->left);
                if (del == nullptr)
                {
                    return;
                }
            }
        }
    }

    Node* u = del -> up;
    Node* le = del -> left;
    Node* r = del -> right;

    if (le == nullptr && r == nullptr)
    {
        if (u->left == del)
        {
            u->left = nullptr;
        }
        else
        {
            u->right = nullptr;
        }
    }

    else if (le == nullptr)
    {
        if (u->left == del)
        {
            u->left = del->right;
        }
        else
        {
            u->right = del->right;
        }
        del->right->up = u;
    }

    else if (r == nullptr)
    {
        if (u->left == del)
        {
            u->left = del->left;
        }
        else
        {
            u->right = del->left;
        }
        del->left->up = u;
    }

    else
    {
        Node* next = del->right;
        while(next -> left != nullptr)
        {
            next = next->left;
        }

        del->value = next->value;
        if (next != del->right)
        {
            next->up->left = next->right;
            if (next->right != nullptr)
            {
                next->right->up = next->up;
            }
        }
        else
        {
            next->up->right = next->right;
            if (next->right != nullptr)
            {
                next->right->up = next->up;
            }
        }
    }

    delete[] del;
}

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
    int mas[7] = {6,7,8,4,9,11,5};
    for (int i = 0; i < 7; i++)
    {
        add3(tre,mas[i]);
    }
    std::cout << count_height(tre);
    std::cout << std::endl;
    preorder(tre->begin_node);
    std::cout << std::endl;

    Node* d = Find(6 ,tre -> begin_node);
    std::cout << d->value << std::endl;
    d = Find(2, tre -> begin_node);

    Delete_value(tre, 5);
    preorder(tre->begin_node);
    std::cout << std::endl;
    Delete_value(tre, 5);
    preorder(tre->begin_node);
    std::cout << std::endl;
    Delete_value(tre, 6);
    preorder(tre->begin_node);
    std::cout << std::endl;
}
