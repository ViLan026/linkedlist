#include "stack.hpp"
#include "linkedlist.hpp"
#include "element.hpp"
#include <iostream>

using namespace std;

Stack::Stack()
{
    this->nNum = 0;
    this->llist = new linkedlist();
}
Stack::Stack(int x)
{
    this->nNum = 1;
    element *moi = new element();
    this->llist = new linkedlist();
    this->llist->InsertFirst(moi);
}

int Stack::getN()
{
    return llist->getCnt();
}

void Stack::in()
{
    this->llist->Travel();
}

void Stack::PushStack(int x)
{
    element *p = new element(x);
    this->llist->InsertFirst(p);
}

int Stack::PopStack()
{
    if (this->llist->getCnt() == 0)
    {
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return 0;
    }
    int tmp = this->llist->getHead()->getData();
    this->llist->RemoveFrirst();
    return tmp;
}

int Stack::getData()
{
    return this->llist->getHead()->getData();
}

void Stack::pushBack(int x)
{
    element *moi = new element(x);
    this->llist->InsertTail(moi);
}

int Stack::popBack()
{
    if (this->llist->getCnt() == 0)
    {
        cout << "STACK RONG, KHONG LAY DUOC PHAN TU" << endl;
        return 0;
    }
    element *tmp = this->llist->getHead();
    while (tmp->Getpointer() != nullptr)
    {
        tmp = tmp->Getpointer();
    }
    int ans = tmp->getData();
    this->llist->Removetail();
    return ans;
}

void Stack::them(int x)
{
    element *moi = new element(x);
    llist->InsertFirst(moi);
}
