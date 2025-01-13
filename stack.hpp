#ifndef stack_hpp
#define stack_hpp
#include "linkedlist.hpp"

class Stack
{
private:
    int nNum;
    linkedlist *llist;

public:
    Stack();
    Stack(int);
    void in();
    int getData();
    void PushStack(int x); // thêm vào đầu
    int PopStack();        // lấy ở đầu
    int getN();
    void pushBack(int); // thêm cuối
    int popBack();      // lấy cuối
    void them(int x);
};

#endif