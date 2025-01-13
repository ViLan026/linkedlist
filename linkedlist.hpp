#ifndef linkedlist_hpp
#define linkedlist_hpp

#include "element.hpp"

class linkedlist
{
private:
    int count;
    element *head;
    element *tail;

public:
    linkedlist()
    {
        count = 0;
        head = tail = nullptr;
    };
    virtual ~linkedlist() {};

    int getCnt() { return count; }

    element *getHead() { return head; }
    void setHead(element *moi) { head = moi; }

    element *getTail() { return tail; }
    void setTail(element *moi) { tail = moi; }

    void InsertFirst(element *moi);
    void InsertTail(element *moi);
    void chenP(element *moi, element *p); // chèn một element mới sau element p
    void Travel();
    void RemoveFrirst();
    void Removetail();
    void xoaP(element *p); // xóa element p
    void removeAll();
    int sumList();
    int maxList();
    int nTo(int);
    int countPrime();
    bool trungSo(int x); // Hàm kiểm tra số trùng
};

#endif