#include <iostream>
#include "s_array.h"
void actions()
{
    int ans , element;
    operations object;
    do
    {
        std::cout<<"\nThese are the following operations on the stack.\n1. Push\n2. Pop\n3. Get Top\n4. Display\n5. Exit\n";
        std::cout<<"\nEnter Your Input:\n";
        std::cin>>ans;
        switch (ans)
        {
            case 1 :
            {
                std::cout<<"\nEnter the data to be inserted:\n";
                std::cin>>element;
                object.push(element);
                break;
            }

            case 2 : object.pop();
                break;

            case 3 : object.first();
                break;

            case 4 : object.display();
                break;

            case 5 : exit(0);

            default : std::cout<<"\nEnter a valid choice.\n";
        }
    }while(true);
}
int main()
{
    actions();
}