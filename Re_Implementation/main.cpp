#include <iostream>
#include "QuickSort.h"

int main()
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
    Quick_sort(array, 0 , Size-1);

    std::cout<<"\nSorted array: \n\n";
    for(int i = 0; i < Size; i++)
        std::cout<<array[i]<<"  ";
    return 0;
}