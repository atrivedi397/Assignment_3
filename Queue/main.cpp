#include <iostream>
#include "queue.h"
int main() 
{
    std::cout<<"\nI am  circular : \n";
    C_Q* object_cq;
    object_cq = new C_Q;
    object_cq->display();
    object_cq->enqueue(54);
    object_cq->enqueue(65);
    object_cq->display();
    object_cq->enqueue(87);
    object_cq->display();
    object_cq->deque();
    object_cq->display();
    object_cq->deque();
    object_cq->enqueue(97);
    object_cq->display();


    std::cout<<"\nI am linear :\n";
    auto object_lq = new L_Q;
    object_lq->display();
    object_lq->enqueue(54);
    object_lq->enqueue(65);
    object_lq->display();
    object_lq->enqueue(87);
    object_lq->display();
    object_lq->deque();
    object_lq->display();
    object_lq->deque();
    object_lq->enqueue(97);
    object_lq->display();

    std::cout<<"\nI am priority :\n";
    auto object_pq = new objects;
    object_pq->display();
    object_pq->create_node(54 , 2);
    object_pq->create_node(65 , 3);
    object_pq->display();
    object_pq->create_node(87 , 1);
    object_pq->display();
    object_pq->delete_node();
    object_pq->display();
    object_pq->delete_node();
    object_pq->create_node(97 , 6);
    object_pq->display();
    delete object_pq;
}