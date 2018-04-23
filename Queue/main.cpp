#include <iostream>
#include "queue.h"
int main() {
    C_Q* object;
    object = new C_Q;
    object->display();
    object->enqueue(54);
    object->enqueue(65);
    object->display();
    object->enqueue(87);
    object->display();
    object->deque();
    object->display();
    object->deque();
    object->enqueue(97);
    object->display();
    delete object;
    return 0;
}