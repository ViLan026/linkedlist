#ifndef queue_hpp
#define queue_hpp
#include "linkedlist.hpp"

class Queue
{
private:
    linkedlist *llist;

public:
    Queue();
    Queue(int);
    void in();
    int getN();
    int getData();
    void EnQueue(int); // thêm đầu
    int DeQueue();     // lấy cuối

    void pushBack(int x); // thêm cuối
    int popFront();       // lấy đầu
};

#endif