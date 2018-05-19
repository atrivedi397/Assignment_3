//inclusion in main makes more sense because it makes the main.cpp independent of any other file
//inclusion which consist required header files.

#include<iostream>
#include "s_array.h"

int main()
{
    s_array obj;
    obj.push(8);
    obj.push(3);
    obj.push(5);
    obj.push(2);
    obj.push(4);
    obj.recent_push();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.recent_push();
    obj.pop();
}