///**********Queue Implemented Using Array*********///

#pragma once

class Q
{
protected:
    int front , rear , Size , *queue;
public:
    virtual void enqueue(int element) = 0;
    virtual void deque() = 0;
    virtual void display() = 0;
    Q() : front(-1) , rear(-1) , Size (0) , queue(nullptr){}
    virtual ~Q() = 0 {};
};

///******Linear Queue Using Array*******///

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
    ~Q() : {delete[] queue;}
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

///************Circular Queue Using Array**********///

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
    ~Q() : {delete[] queue;}
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

// Created by atrivedi on 4/20/18.
//