#include <iostream>
#include "BST.h"

int main()
{
    int element;
    op_bst object;
    object.insert_recursive(r_root , 120);
    object.insert_recursive(r_root , 10);
    object.insert_recursive(r_root , 1);
    object.insert_recursive(r_root , 140);
    object.display_in(r_root);
    std::cout<<std::endl;
    object.display_pre(r_root);
    std::cout<<std::endl;
    object.display_post(r_root);

    std::cout<<"\n\n";
    object.insert_iteration(120);
    object.insert_iteration(10);
    object.insert_iteration(1);
    object.insert_iteration(140);
    object.display_in(i_root);
    std::cout<<std::endl;
    object.display_pre(i_root);
    std::cout<<std::endl;
    object.display_post(i_root);

    object.r_search(r_root , 15);
    object.i_search(3);

    object.bst_max(i_root);
    object.bst_min(i_root);
    object.bst_max(r_root);
    object.bst_min(r_root);
}

