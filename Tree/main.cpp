#include <iostream>
#include "BST.h"

void operations()
{
    int element , answer; op_bst object;
    while(true)
    {
        std::cout<<"\nBinary Search Tree Functions:\n1. Add Node(Iteration)\n2. Add Node (Recursion)\n3. Search(Iteration)\n";
        std::cout<<"4. Search(Recursion)\n5. Find Minimum\n6. Find Maximum\n7. Display(In Order)\n";
        std::cout<<"8. Display(Pre Order)\n9. Display(Post Order)\n10. Find Height\n11. Total Nodes\n12. Exit\n\n";

        std::cin>>answer;

        switch(answer)
        {
            case 1 : std::cout<<"\nEnter the value:\n";
                std::cin>>element;
                object.insert_iteration(element);
                break;

            case 2 : std::cout<<"\nEnter the value:\n";
                std::cin>>element;
                object.insert_recursive(root , element);
                break;

            case 3 : std::cout<<"\nEnter element to be searched :\n";
                std::cin>>element;
                object.i_search(element);
                break;

            case 4 : std::cout<<"\nEnter element to be searched :\n";
                std::cin>>element;
                object.r_search(root, element);
                break;

            case 5 : object.bst_min(root);
                break;

            case 6 : object.bst_max(root);
                break;

            case 7 : object.display_in(root);
                break;

            case 8 : object.display_pre(root);
                break;

            case 9 : object.display_post(root);
                break;

            case 10 : std::cout<<"\nThe height is  : "<<object.height(root)<<std::endl;
                break;

            case 11 : std::cout<<"\nTotal nodes are : "<<object.total_nodes(root)<<std::endl;
                break;

            case 12 : exit(0);

            default : std::cout<<"\nEnter a valid choice.\n";
        }
    }
}
int main()
{
    operations();
}