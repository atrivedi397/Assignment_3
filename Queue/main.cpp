#include <iostream>
#include "queue.h"
template <typename T>
//reference to a pointer which is of type T is passed
void functions(T*& object)
{
    do
    {
        int element , answer;
        std::cout<<"\n\nThe Functions of a Queue are following\n1. Enqueue\n2. Deque\n3. Display\n4. Exit\n";
        std::cin>>answer;

        switch (answer)
        {
            case 1 :  std::cout<<"\nEnter the element to be enqueued.\n";
                      std::cin>>element;
                      object->enqueue(element);
                      break;

            case 2 :  object->deque();
                      break;

            case 3 :  object->display();
                      break;

            case 4 :  exit(0);

            default : std::cout<<"\nPlease enter a valid choice. !!!\n";
        }
    }while(true);
}

//function overloading
void functions(P_Q*& object)
{
    do
    {
        int element , prior = -1 ,answer;
        std::cout<<"\nThe Functions of a Queue are following\n1. Enqueue\n2. Deque\n3. Display\n4. Exit\n";
        std::cin>>answer;

        switch (answer)
        {
            case 1 :  std::cout<<"\nEnter the element and its priority to be enqueued.\n";
                std::cin>>element>>prior;
                object->create_node(element , prior);
                break;

            case 2 :  object->delete_node();
                break;

            case 3 :  object->display();
                break;

            case 4 :  exit(0);

            default : std::cout<<"\nPlease enter a valid choice. !!!\n";
        }
    }while(true);
}

int main() 
{
    int answer;

    std::cout<<"\nWhich Queue you want to work with ?\n1. Linear\n2. Circular\n3. Priority\n4. Any other key to Exit\n";
    std::cin>>answer;
    switch (answer)
    {
        case 1 :
        {
            auto l_q  = new L_Q;
            functions(l_q);
            delete l_q;
        }

        case 2 :
        {
            auto c_q = new C_Q;
            functions(c_q);
            delete c_q;
        }

        case 3 :
        {
            auto p_q = new P_Q;
            functions(p_q);
            delete p_q;
        }

        default : std::cout<<"\nExiting\n";
                  exit(0);
        }
}