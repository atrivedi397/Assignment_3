///******************Implementation by using Array******************///

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
    if(top == -1)
        std::cout<<"\nStack is empty.!! Nothing on top.\n";
    else
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
    if(top == -1)
    {
        std::cout<<"\nNothing to Display..!! Stack is empty.\n";
    }
    else
    {
        std::cout<<"\nYour stack is :\n";
        for(int i = top; i >= 0; i--)
        {
            std::cout<<stack[i]<<std::endl;
        }
    }
}

///***************Implementation using Singly Linked List****************///
class s_ll
{
public:
    int data;
    s_ll* next;
    s_ll* prev;
    s_ll()                       //default constructor
            :data(0) , next(nullptr) , prev(nullptr) {}
};

class functions : public s_ll
{
public:
    int size , count = 0;
    s_ll* top_ptr = nullptr;      //pointing at the top
    functions()                  //default constructor
    {
        int size_of_stack;
        std::cout<<"\nWhat is the size of the stack ?\n";
        std::cin>>size_of_stack;
        size = size_of_stack;
    }
    void push(int element);
    void pop();
    void display();
    void first();
};

void functions::push(int element)
{
    s_ll* new_node;
    new_node = new s_ll;
    new_node->data = element;

    if(count >= size)
    {
        std::cout<<"\nStack Overflow..!!!\n";
    }
    else if(top_ptr == nullptr)
    {
        count++;
        top_ptr = new_node;
        return;
    }
    else
    {
        count++;
        top_ptr->next = new_node;
        new_node->prev = top_ptr;
        top_ptr = new_node;
    }
}

void functions::pop()
{
    if(top_ptr == nullptr)
        std::cout<<"\nUnderflow!!!! . Nothing to pop.\n";
    else
    {
        count--;
        s_ll* temp;
        temp = top_ptr;
        top_ptr = temp->prev;
        std::cout<<"\nThe popped element is : "<<temp->data<<"\n";
        delete temp;
    }

}

void functions::display()
{
    if(top_ptr == nullptr)
        std::cout<<"\nStack is empty. Nothing to show.\n";
    else
    {
        s_ll* temp = top_ptr;
        std::cout<<"\nYour stack is : \n";
        while(temp != nullptr)
        {
            std::cout<<temp->data<<std::endl;
            temp = temp->prev;
        }
    }
}

void functions::first()
{
    if(top_ptr == nullptr)
        std::cout<<"\nStack is empty.!! Nothing on top.\n";
    else
        std::cout<<std::endl<<top_ptr->data<<" is at top \n";
}

//
// Created by atrivedi on 4/15/18.
