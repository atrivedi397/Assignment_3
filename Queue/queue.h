///**********Queue Implemented Using Array*********///

#pragma once

//using interface
class Q
{
protected:
    int front , rear , Size , *queue;
public:
    //pure virtual functions
    virtual void enqueue(int element) = 0;
    virtual void deque() = 0;
    virtual void display() = 0;
    Q() : front(-1) , rear(-1) , Size (0) , queue(nullptr){}
    virtual ~Q()
    {
        delete[] queue;
    }
};

///********************************Linear Queue Using Array***************************************///

class L_Q : public Q
{
public:
    void enqueue(int element) override ;
    void deque() override ;
    void display() override ;
    L_Q()
    {
        std::cout<<"\nWhat is the Size of the Queue ?\n";
        std::cin>>Size;
        queue = new int[Size];
    }
    ~L_Q() override
    {
        delete[] queue;
    }


};

void L_Q :: enqueue(int element)
{
    if(rear == -1)
    {
        queue[++rear] = element;
        front++;
    }
    else if(rear == (Size-1))
        std::cout<<"\nQueue Overflow..!!!\n";
    else
        queue[++rear] = element;
}

void L_Q::deque()
{
    if(front == -1 || front == rear+1)
        std::cout<<"\n!!!Underflow ... Nothing to Deque.\n";
    else
        std::cout<<"\nThe removed element is :"<<queue[front++]<<std::endl;
}

void L_Q::display()
{
    if(rear == -1)
        std::cout<<"\nNothing to display.\n\n";
    else
        for(int i = front; i <= rear ; i++)
            std::cout<<queue[i]<<"\n";
}

///***********************************Circular Queue Using Array*****************************************///

class C_Q : public Q
{
private:
    int count;
public:
    void enqueue(int element) override;
    void deque() override;
    void display() override;
    C_Q() : count(0)
    {
        std::cout<<"\nWhat is the size of Queue.\n";
        std::cin>>Size;
        queue = new int[Size];
    }
    ~C_Q() override
    {
        std::cout<<"\nDeleted \n"<<std::endl;
        delete[] queue;
    }
};

void C_Q::enqueue(int element)
{
    if(count == Size || rear == front-1)
        std::cout<<"\nQueue Overflow !!!\n";
    else if(front == -1 && rear == -1)
    {
        queue[++rear] = element;
        count++;
        ++front;
    }
    else if(rear == (Size-1))
    {
        rear = 0;
        queue[++rear] = element;
        count++;
    }
    else
    {
        queue[++rear] = element;
        count++;
    }
}

void C_Q::deque()
{
    if(count == 0)
        std::cout<<"\nUnderflow !!!...Nothing to delete.\n";
    else if(front == Size-1)
    {
        std::cout<<"\nThe removed element is : "<<queue[front]<<std::endl;
        count--;
        front = 0;
    }
    else
        std::cout<<"\nThe removed element is : "<<queue[front++]<<std::endl;
}

void C_Q::display()
{
    if(count == 0)
        std::cout<<"\nNothing to display.\n";
    else
    {
        std::cout<<"\nYour Queue is :\n";
        if(rear >= front)
            for(int i = front; i <= rear; i++)
                std::cout<<queue[i]<<std::endl;
        else
        {
            for(int i = front; i <= Size; i++)
                std::cout<<queue[i]<<std::endl;
            for(int j = rear; j <= front; j++)
                std::cout<<queue[j]<<std::endl;
        }
    }
}


///***************************Priority Queue Using Linked Lists******************************///

struct node
{
    int coefficient;
    int degree;    //priority
    node* next;
};

class objects
{
private:
    node* front = nullptr;
    node* rear = nullptr;

public:
    void create_node(int coeff, int priority);
    node* delete_node();
    node* get_front_rear(int a);
    node* traversal(int priority);
    void display();
};

void objects::create_node(int coeff, int priority)
{
    node* temp; node* traversed;    //traversed is used for position where it has to be inserted according to priority
    temp = new node;
    temp->coefficient = coeff;
    temp->degree = priority;
    temp->next = nullptr;

    //insertion if queue is blank
    if(front == nullptr)
    {
        front = temp;
        rear = temp;
    }
    //insertion if queue's front's priority is less than given then creating a new front
    else if(priority < front->degree)
    {
        temp->next = front;
        front = temp;
    }
    //insertion if queue's rear's priority is less than or equal given then creating a new rear and F_C_F_S rule
    else if(priority >= rear->degree)
    {
        rear->next = temp;
        rear = rear->next;
    }
        //inserting according to the priority
    else
    {
        traversed = traversal(priority);
        temp->next = traversed->next;
        traversed->next = temp;
    }
}

node* objects:: get_front_rear(int a)
{
    return a == 1 ? front : rear;
}

node *objects::delete_node()
{
    node* temp;
    temp = get_front_rear(1);

    front = temp->next;
    delete temp;

    return front;
}

node *objects::traversal(int priority)
{
    node* temp = get_front_rear(1);
    while(temp->next->degree <= priority)
        temp = temp->next;

    return temp;
}

void objects::display()
{
    node* ptr = get_front_rear(1);

    std::cout<<"\n\nYour priority queue is as follows (the priority is in the brackets):\n\n";
    while(ptr != nullptr)
    {
        std::cout<<ptr->coefficient<<"("<<ptr->degree<<")<-";
        ptr =  ptr->next;
    }
    delete ptr;
}

// Created by atrivedi on 4/20/18.
//