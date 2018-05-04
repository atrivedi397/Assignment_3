#pragma once

struct node
{
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
    //node* parent = nullptr;
}*r_root , *i_root;


class op_bst
{
public:
    void insert_iteration(int element);
    void insert_recursive(node*& new_root , int element);
    void display_in(node*& new_root);
    void display_pre(node*& new_root);
    void display_post(node*& new_root);
    node* r_search(node*& new_root , int data);
    void i_search(int data);
    void bst_min(node*& new_root);
    void bst_max(node*& new_root);
};

////*********Iteration Insert*******///////
void op_bst::insert_iteration(int element)
{
    node* traverse = i_root;
    node* temp2 = nullptr;
    auto temp  =  new node;
    temp->data = element;

    if(traverse == nullptr)
        i_root = temp;
    else
    {
        while(traverse != nullptr)
        {
            temp2 = traverse;

            if(temp->data > traverse->data)
                traverse = traverse->right;
            else
                traverse = traverse->left;
        }
        //temp->parent = temp2;
        //if(temp2 == nullptr)
            //r_root = temp;
        if(temp->data < temp2->data)
            temp2->left = temp;
        else
            temp2->right = temp;
    }
}
///////********Recursive Insert********///////
void op_bst :: insert_recursive(node*& new_root, int element)
{
    if(new_root == nullptr)
    {
        auto root = new node;
        root->data = element;
        new_root = root;
    }
    else if(new_root->data > element)
        insert_recursive(new_root->left , element);
    else
        insert_recursive(new_root->right , element);
}

////////*******************Depth First Traversal***********************/////////

///in_order traversal
void op_bst :: display_in(node*& new_root)
{
    if (! new_root)
        return;
    display_in(new_root->left);
    std::cout << new_root->data << " ";
    display_in(new_root->right);
}

///pre-order traversal
void op_bst :: display_pre(node*& new_root)
{
    if (new_root == nullptr)
        return;
    std::cout << new_root->data << " ";
    display_pre(new_root->left);
    display_pre(new_root->right);
}

///post-order traversal
void op_bst :: display_post(node*& new_root)
{
    if (new_root == nullptr)
        return;
    display_post(new_root->left);
    display_post(new_root->right);
    std::cout << new_root->data << " ";
}

////////////***********Searching In A BST (Recursive)*************///////

node * op_bst::r_search(node*& new_root , int data)
{
    if(new_root == nullptr || new_root->data == data)
        return new_root;
    if(new_root->data < data)
        return r_search(new_root->right , data);
    else
        return r_search(new_root->left , data);
}

////////////***********Searching In A BST (Iterative)*************///////

void op_bst::i_search(int data)
{
    bool flag = false;
    node* traverse =  i_root;
    if(traverse == nullptr)
        std::cout<<"\n\nNothing to search.\n";
    else
    {
        while(traverse != nullptr)
        {
            if(traverse->data == data)
                flag = true;
            else if(traverse->data < data)
                traverse = traverse->right;
            else
                traverse = traverse->left;
        }
    }

    if(flag)
        std::cout<<"\n\nData exits in the tree.\n"<<std::endl;
    else
        std::cout<<"\n\nData not found.\n";
}

/////*********Minimum in a BST********/////
void op_bst::bst_min(node*& new_root)
{
    while(new_root->left != nullptr)
        new_root = new_root->left;

    std::cout<<"\nThe minimum of this BST is : "<<new_root->data<<std::endl;
}

/////*********Maximum in a BST********/////
void op_bst::bst_max(node*& new_root)
{
    while(new_root->right != nullptr)
        new_root = new_root->right;

    std::cout<<"\nThe maximum of this BST is : "<<new_root->data<<std::endl;
}




// Created by atrivedi on 4/27/18.

