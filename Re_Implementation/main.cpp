#include <iostream>
#include "QuickSort.h"
#include "BST.h"
void Quick()
{
    int Size;
    std::cout << "Provide size:" << std::endl;
    std::cin>>Size;
    auto *array = new int[Size];

    for(int i = 0; i < Size; i++)
    {
        std::cout<<"\nEnter the value "<<i<<": ";
        std::cin>>array[i];
    }

///passing from 0 to last index number to sort the while array
    Quick_sort2(array, 0 , Size-1);

    std::cout<<"\nSorted array: \n\n";
    for(int i = 0; i < Size; i++)
        std::cout<<array[i]<<"  ";

}

void BST()
{
    int element , answer; operations object;
    while(true)
    {
        std::cout << "\nBinary Search Tree Functions:\n1. Add Node(Iteration)\n";
        std::cout << "2. Search(Recursion)\n3. Find Minimum\n4. Display(In Order)\n5. Delete\n6. Exit\n\n";

        std::cin >> answer;

        switch (answer) {
            case 1 : std::cout << "\nEnter the value:\n";
                     std::cin >> element;
                     object.insert_i(element);
                     break;

            case 2 : std::cout << "\nEnter element to be searched :\n";
                     std::cin >> element;
                     std::cout << object.search_r(root, element);
                     break;

            case 3 : object.minimum(root);
                     break;

            case 4 : object.in_order(root);
                     break;

            case 5 : std::cout << "\nEnter the value to be deleted:\n";
                     std::cin >> element;
                     object.delete_node(root , element);

            case 6 : exit(0);

            default : std::cout << "\nGet Out\n";
        }
    }
}

int main()
{
    int choice;
    std::cout<<"\nEnter Your Choice :\n1. QuickSort\n2. BST\n";
    std::cin>>choice;
    switch (choice)
    {
        case 1 : Quick();
        break;

        case 2 : BST();
        break;

        default: std::cout<<"End";
    }
    return 0;
}