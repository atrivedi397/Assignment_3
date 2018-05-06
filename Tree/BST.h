#pragma once

struct node
{
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
}*root;


class op_bst
{
public:
    int count_nodes = 1;
    void insert_iteration(int element);
    void insert_recursive(node*& new_root , int element);
    void display_in(node*& new_root);
    void display_pre(node*& new_root);
    void display_post(node*& new_root);
    void r_search(node* new_root , int data);
    void i_search(int data);
    void bst_min(node* new_root);
    void bst_max(node* new_root);
    int total_nodes(node* new_root);
    int height(node* new_root);
};

////*********Iteration Insert*******///////
void op_bst::insert_iteration(int element)
{
    node* traverse = root;
    node* temp2 = nullptr;
    auto temp  =  new node;
    temp->data = element;

    if(traverse == nullptr)
        root = temp;
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

void op_bst::r_search(node* new_root , int data)
{
    if(new_root == nullptr)
        std::cout<<"\nData not found.\n";
    else if(new_root->data == data)
        std::cout<<"\n\nData exits in the tree.\n"<<std::endl;
    else if(new_root->data < data)
        return r_search(new_root->right , data);
    else if(new_root->data > data)
        return r_search(new_root->left , data);
    else
        std::cout<<"\nData not found.\n";
}

////////////***********Searching In A BST (Iterative)*************///////

void op_bst::i_search(int data)
{
    node* traverse =  root;
    if(traverse == nullptr)
        std::cout<<"\n\nNothing to search.\n";
    else
    {
        while(traverse != nullptr)
        {
            if(traverse->data == data)
            {
                std::cout<<"\n\nData exits in the tree.\n"<<std::endl;
                return;
            }
            else if(traverse->data < data)
                traverse = traverse->right;
            else
                traverse = traverse->left;
        }
        std::cout<<"\nData not found.\n";
    }
}

/////*********Minimum in a BST********/////
void op_bst::bst_min(node* new_root)
{
    while(new_root->left != nullptr)
        new_root = new_root->left;

    std::cout<<"\nThe minimum of this BST is : "<<new_root->data<<std::endl;
}

/////*********Maximum in a BST********/////
void op_bst::bst_max(node* new_root)
{
    while(new_root->right != nullptr)
        new_root = new_root->right;

    std::cout<<"\nThe maximum of this BST is : "<<new_root->data<<std::endl;
}
////////*************Total Height of a tree**********///////
int op_bst::height(node* new_root)
{
    if(new_root == nullptr)
        return 0;
    else
    {
        int l_height = height(new_root->left);
        int r_height = height(new_root->right);
        if (l_height > r_height)
            return l_height + 1; ///+1 is done for counting the current node
        else
            return r_height + 1;
    }
}
/////**********Total Number of nodes is a BST*********//////////////
int op_bst::total_nodes(node* new_root)
{
    if(new_root == nullptr)
       return 0;
    if(new_root->left != nullptr)
    {
        ++count_nodes;
        count_nodes = total_nodes(new_root->left);
    }
    if(new_root->right != nullptr)
    {
        ++count_nodes;
        count_nodes = total_nodes(new_root->right);
    }
       return count_nodes;
}
// Created by atrivedi on 4/27/18.

