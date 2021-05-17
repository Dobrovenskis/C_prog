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

void find_all_leaves(Node* n)
{
    if (n->left == nullptr && n->right == nullptr)
    {
        std::cout << n -> value << " ";
    }


   if (n->right != nullptr)
   {
       find_all_leaves(n->right);
   }
   if (n->left != nullptr)
   {
       find_all_leaves(n->left);
   }
}

int count_height(Tre* tre)
{
    return tre->begin_node->height;
}

void fix_height( Node* n)
{
    if (n->left == nullptr || n->right == nullptr)
    {
        n->height = 1;
        return;
    }
    int h_left = n->left->height;
    int h_right = n->right->height;
    if (h_left > h_right)
    {
        n ->height = h_left+1;
    }
    else
    {
        n->height = h_right+1;
    }
}
void r_rotation(Node* a)
{
    /*
        a              b
       / \            / \
      b   R   ->     L   a
     / \                / \
    L   C              C   R
    */
    Node* b = a->left;
    if (b == nullptr)
    {
        std::cout << "Something is wrong";
        return;
    }
    Node* C = b->right;

    a->left = C;
    b->up = a->up;
    if (a->up!=nullptr)
    {
        if(a->up->left == a)
        {
            a->up->left = b;
        }
        else
        {
            a->up->right = b;
        }
    }
    a->up = b;
    if (C!=nullptr)
    {
        C->up = a;
    }
    b->right = a;

    fix_height(a);
    fix_height(b);
}

void l_rotation(Node* a)
{
    /*
        b              a
       / \            / \
      a   R   <-     L   b
     / \                / \
    L   C              C   R
    */
    Node* b = a->right;
    if (b == nullptr)
    {
        std::cout << "Something is wrong";
        return;
    }
    Node* C = b->left;
    Node* R = b->right;
    Node* L = a->left;
    int b_v = b->value;
    b->value = a->value;
    a->value =b_v;

    a->right = R;
    a->left = b;
    b->right = C;
    b ->right = L;
    if (L!=nullptr)
    {
        L->up = b;
    }
    if (C!=nullptr)
    {
        C->up = b;
    }
    if (R!=nullptr)
    {
        R->up = a;
    }

    fix_height(a);
    fix_height(b);
}

/*
void ll_rotation(Node* a)
{
    /*
         a                   c
        / \                 / \
       /   \               /   \
      L     b     ->      a     b
           / \           / \   / \
          c   R         L   M N   R
         / \
        M   N
    *//*
    Node* b = a->right;
    if(b->left == nullptr)
    {
        std::cout << "Something is wrong";
        return;
    }
    Node* c = b->left;
    Node* M = c->left;
    Node* N = c->right;

    c->left = a;
    c->right = b;
    c->up = a->up;
    a->up = c;
    b->up = c;
    a->left = M;
    if (M != nullptr)
    {
        M->up = a;
    }
    b->left = N;
    N->up = b;

    fix_height(a);
    fix_height(b);
    fix_height(c);
}

void rr_rotation(Node* a)
{
    /*
         a                   c
        / \                 / \
       /   \               /   \
      b     R     ->      b     a
     / \                 / \   / \
    L   c               L   M N   R
       / \
      M   N
    *//*
    Node* b = a->left;
    if(b->right == nullptr)
    {
        std::cout << "Something is wrong";
        return;
    }
    Node* c = b->right;
    Node* M = c->left;
    Node* N = c->right;
    int h = a->height;

    c->up = a->up;
    c->right = a;
    c->left = b;
    b->up = c;
    a->up = c;
    b->right = M;
    M->up = b;
    a->left = N;
    N->up = a;

    fix_height(a);
    fix_height(b);
    fix_height(c);
}
*/

int count_delta(Node* a)
{
    int delta = a->right->height - a->left->height;
}

void balance_one(Node* a)
{
    fix_height(a);
    int delta = count_delta(a);
    if(delta==2)
    {
        if(count_delta(a->right) < 0)
        {
            r_rotation(a->right);
        }
        l_rotation(a);
    }
    if(delta == -2)
    {
        if (count_delta(a->left) > 0)
        {
            l_rotation(a->left);
        }
        r_rotation(a);
    }
}

void balance_postorder(Node* n)
{
   if (n->right != nullptr)
   {
       balance_postorder(n->right);
   }
   if (n->left != nullptr)
   {
       balance_postorder(n->left);
   }

   balance_one(n);
}

void balance_trea(Tre* trea)
{
    bool finih = true;
    while (finih)
    {
        int h = count_height(trea);
        balance_postorder(trea->begin_node);
        if (count_height(trea)==h)
        {
            finih = false;
        }
    }
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
    find_all_leaves(tre->begin_node);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    l_rotation(tre->begin_node);
    preorder(tre->begin_node);
}
