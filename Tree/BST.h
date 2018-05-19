#pragma once

///Tree nodes are defined, for the child nodes left and right are NULL by default
struct node
{
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
}*root;   ////pointer for the root of the tree is created


///Class defining Operations On BST
class op_bst
{
public:
    int count_nodes = 1;

    ///Function for iterative node creation
    void insert_iteration(int element);

    ///Function for recursive node creation
    void insert_recursive(node*& new_root , int element);

    ///displaying in order traversal
    void display_in(node*& new_root);

    ///displaying pre order traversal
    void display_pre(node*& new_root);

    ///displaying post order traversal
    void display_post(node*& new_root);

    ///recursive search in a BST
    void r_search(node* new_root , int data);

    ///iterative search in a BST
    void i_search(int data);

    ///minimum in a BST
    void bst_min(node* new_root);

    ///maximum in a BST
    void bst_max(node* new_root);

    ///total Nodes (NOT Working Properly)
    int total_nodes(node* new_root);

    ///Height of a BST
    int height(node* new_root);
};

////*********Iteration Insert*******///////
void op_bst::insert_iteration(int element)
{
    node* traverse = root;         ///local variable to traverse from root , hence assigned as root
    node* temp2 = nullptr;         ///temporary node to work as a "parent node"
    auto temp  =  new node;        ///temporary node created to add
    temp->data = element;          ///data inserted in that temporary variable which is to be added

    if(traverse == nullptr)        ////is equal to if root == NULL
        root = temp;               ////if yes then making that temporary node as our Root
    else                           ///otherwise
    {
        while(traverse != nullptr)   ///we traverse to the node till the data is there
        {
            temp2 = traverse;   ///if we don't put temp2 = traverse , we'll always be at the NULL and hence can't insert
                                /// so we have to store the value of the traverse in a variable to avoid differences of parent node
            if(temp->data > traverse->data)     ///comparing the data of the node
                traverse = traverse->right;     ///to be inserted and where to traverse left or right
            else
                traverse = traverse->left;
        }
        if(temp->data < temp2->data)           ///Now Comparing and inserting the node at the particular position
            temp2->left = temp;
        else
            temp2->right = temp;
    }
}
///////********Recursive Insert********///////
void op_bst :: insert_recursive(node*& new_root, int element)
{
    if(new_root == nullptr)     ///checking if there is already BST created or not, means if root is NULL
    {
        auto root = new node;     ///then creating a node
        root->data = element;     ///adding element to the temporary node
        new_root = root;          /// making that node as root
    }
    else if(new_root->data > element)    ///now comparing the data
        insert_recursive(new_root->left , element);      ///calling the function again to insert
    else
        insert_recursive(new_root->right , element);
}

////////*******************Depth First Traversal***********************/////////

///in_order traversal
void op_bst :: display_in(node*& new_root)      ///root node is to be passed
{
    if (! new_root)                 ///if root s NULL then return
        return;
    display_in(new_root->left);         ///else the "In Order Traversal means Go to ->Left Subtree->(print (root))->Right Subtree"
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
    if(new_root == nullptr)                 ///if root is Null then return
        std::cout<<"\nData not found.\n";
    else if(new_root->data == data)               ///if found
        std::cout<<"\n\nData exits in the tree.\n"<<std::endl;
    else if(new_root->data < data)               ///comparing data if larger then passing right subtree
        return r_search(new_root->right , data);
    else if(new_root->data > data)               ///and if data is smaller then passing left subtree
        return r_search(new_root->left , data);
    else                                          ///finally if not found
        std::cout<<"\nData not found.\n";
}

////////////***********Searching In A BST (Iterative)*************///////

void op_bst::i_search(int data)
{
    node* traverse =  root;             ///assigning the root to a local
    if(traverse == nullptr)             ///if root is NULL
        std::cout<<"\n\nNothing to search.\n";
    else
    {
        while(traverse != nullptr)           ///traversing to the final node
        {
            if(traverse->data == data)           ///if Found then return
            {
                std::cout<<"\n\nData exits in the tree.\n"<<std::endl;
                return;
            }
            else if(traverse->data < data)          ///else compare and pass the updated node
                traverse = traverse->right;
            else
                traverse = traverse->left;
        }
        std::cout<<"\nData not found.\n";            ///finally if not found
    }
}

/////*********Minimum in a BST********/////
void op_bst::bst_min(node* new_root)              ////maximum will always be in left subtree
{
    while(new_root->left != nullptr)              ////hence always traversing the left subtree
        new_root = new_root->left;

    std::cout<<"\nThe minimum of this BST is : "<<new_root->data<<std::endl;
}

/////*********Maximum in a BST********/////
void op_bst::bst_max(node* new_root)         ////maximum will always be in right subtree
{
    while(new_root->right != nullptr)       ////hence always traversing the right subtree
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

