#include "queue.hpp"
#include "linkedlist.hpp"
#include <iostream>

using namespace std;

Queue::Queue()
{
    this->llist = new linkedlist();
}
Queue::Queue(int x)
{
    element *moi = new element(x);
    this->llist = new linkedlist();
    this->llist->InsertFirst(moi);
}

int Queue::getN()
{
    return this->llist->getCnt();
}
int Queue::getData()
{
    return this->llist->getHead()->getData();
}

void Queue::in()
{
    this->llist->Travel();
}

void Queue::EnQueue(int x)
{
    element *moi = new element(x);
    this->llist->InsertFirst(moi);
}

int Queue::DeQueue()
{
    if (this->llist->getCnt() == 0)
    {
        cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
        return 0;
    }
    int ans = this->llist->getTail()->getData();
    this->llist->Removetail();
    return ans;
}

void Queue::pushBack(int x)
{
    element *p = new element(x);
    this->llist->InsertTail(p);
}

int Queue::popFront()
{
    if (this->llist->getCnt() == 0)
    {
        cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU" << endl;
        return 0;
    }
    int tmp = this->llist->getHead()->getData();
    this->llist->RemoveFrirst();
    return tmp;
}
