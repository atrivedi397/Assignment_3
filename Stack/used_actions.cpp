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

void actions_s_l_l()
{
    int ans , element;
    functions object;
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

void begin()
{
    int answer;
    std::cout<<"\nHow do you want to create stack ?\n\n1. Array\n2. Linked List\n";
    std::cin>>answer;
    if(answer == 1)
        actions();
    else
        actions_s_l_l();
}

//
// Created by atrivedi on 4/21/18.
