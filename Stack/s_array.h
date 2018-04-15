//
// Created by atrivedi on 4/15/18.
//
#pragma once
class s_array
{
public:
    int top = -1 , size;
    s_array()
    {
        int size_of_stack;
        std::cout<<"\nEnter the size of stack: \n";
        std::cin>>size_of_stack;
        size = size_of_stack;
    };
    int* stack = new int[size];
};

class operations : public s_array
{
public:
    void first();
    void push(int element);
    bool pop();
    void display();
};

void operations::first()
{
    std::cout<<std::endl<<stack[top]<<" is at top \n";
}

void operations::push(int element)
{
    if (top == size - 1)
    {
        std::cout << "\nOverflow !!!! Can't Insert More.\n";
        return;
    }
    else
    {
        top++;
        stack[top] = element;
        return;
    }
}

bool operations::pop()
{
    int deleted_ele;
    if(top < 0)
    {
        std::cout<<"\nUnderflow!!! Put some elements first.\n";
        return false;
    }
    else
    {
        deleted_ele = stack[top--];
        std::cout<<"\nThe popped element is : "<<deleted_ele<<std::endl;
        return true;
    }
}

void operations::display()
{
    std::cout<<"\nYour stack is :\n";
    for(int i = top; i >= 0; i--)
    {
        std::cout<<stack[i]<<std::endl;
    }
}