#include "linkedlist.hpp"
#include <iostream>
#include <cmath>
using namespace std;

void linkedlist::InsertFirst(element *moi)
{
    if (this->head == nullptr)
    {
        this->head = this->tail = moi;
    }
    else
    {
        moi->Setpointer(this->head);
        this->head = moi;
    }
    this->count++;
}

void linkedlist::InsertTail(element *moi)
{
    if (this->head == nullptr)
    {
        this->head = this->tail = moi;
    }
    else
    {
        this->tail->Setpointer(moi);
        this->tail = moi;
    }
    this->count++;
}

void linkedlist::chenP(element *moi, element *p)
{
    if (p == this->tail)
    {
        InsertTail(moi);
        this->count++;
        return;
    }
    element *tmp = this->head;
    while (tmp->Getpointer() != nullptr)
    {
        if (p == tmp)
        {
            tmp = p;
            p->Setpointer(moi);
            moi->Setpointer(tmp);
            this->count++;
            return;
        }
        tmp = tmp->Getpointer();
    }
    cout << "element p khong co trong danh sach.\n";
}

void linkedlist::Travel()
{
    element *tmp = this->head;
    while (tmp != nullptr)
    {
        cout << tmp->getData() << " ";
        tmp = tmp->Getpointer();
    }
    cout << endl;
}

void linkedlist::RemoveFrirst()
{
    if (this->head == nullptr)
        return;
    if (this->head == this->tail)
    {
        element *tmp = this->head;
        this->head = this->tail = nullptr;
        delete tmp;
        this->count--;
        return;
    }
    element *tmp = this->head;
    this->head = this->head->Getpointer();
    this->count--;
    delete tmp;
}

void linkedlist::Removetail()
{
    if (this->head == nullptr)
        return;
    if (this->head == this->tail)
    {
        element *tmp = this->head;
        this->head = this->tail = nullptr;
        this->count--;
        delete tmp;
        return;
    }
    element *tmp = this->head;
    while (tmp->Getpointer()->Getpointer() != nullptr)
    {
        tmp = tmp->Getpointer();
    }
    this->tail = tmp;
    this->tail->Setpointer(nullptr);
    tmp = tmp->Getpointer();
    this->count--;
    delete tmp;
}

void linkedlist::xoaP(element *p)
{
    // Mảng chỉ có một phần tử.
    if (this->count == 0)
    {
        cout << "Danh sách rỗng.\n";
        return;
    }
    // if (this->head == p)
    // {
    //     this->head = this->tail = nullptr;
    //     this->count--;
    //     delete p;
    //     return;
    // }
    // Mảng có hai phần tử
    // if ((this->head == p || this->tail == p) && count == 2)
    // {
    //     // Phần tử cần xóa ở đầu
    //     if (this->head == p)
    //     {
    //         this->head = this->tail;
    //         this->count--;
    //         delete p;
    //         return;
    //     }
    //     // Phần tủ cần xóa ở cuối
    //     if (this->tail == p)
    //     {
    //         this->head->Setpointer(nullptr);
    //         this->tail = this->head;
    //         this->count--;
    //         delete p;
    //         return;
    //     }
    // }
    if (this->head == p)
    {
        this->count--;
        this->head = this->head->Getpointer();
        delete p;
        return;
    }
    element *tmp = this->head;
    int n = 0;
    for (int i = 0; i < this->count; ++i)
    {
        if (tmp->Getpointer() == p)
        {
            n = 1;
            break;
        }
        tmp = tmp->Getpointer();
    }
    if (n == 0)
    {
        cout << "Phan tu can xoa khong ton tai trong mang.\n";
        return;
    }
    if (this->tail == p)
    {
        tmp->Setpointer(nullptr);
        this->tail = tmp;
        this->count--;
        delete p;
        return;
    }
    tmp->Setpointer(p->Getpointer());
    this->count--;
    delete p;
}

void linkedlist::removeAll()
{
    this->tail = nullptr;
    while (head != nullptr)
    {
        element *tmp = this->head;
        head = head->Getpointer();
        delete tmp;
    }
    this->count = 0;
}

int linkedlist::sumList()
{
    int tong = 0;
    element *tmp = this->head;
    while (tmp != nullptr)
    {
        tong += tmp->getData();
        tmp = tmp->Getpointer();
    }
    return tong;
}

int linkedlist::maxList()
{
    if (this->count == 0)
    {
        cout << "Danh sach trong.\n";
        return 0;
    }
    int max = head->getData();
    element *tmp = this->head;
    while (tmp != nullptr)
    {
        if (max < tmp->getData())
        {
            max = tmp->getData();
        }
        tmp = tmp->Getpointer();
    }
    return max;
}

int linkedlist::nTo(int n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int linkedlist::countPrime()
{
    int cnt = 0;
    element *tmp = this->head;
    while (tmp != nullptr)
    {
        if (nTo(tmp->getData()))
        {
            cnt++;
        }
        tmp = tmp->Getpointer();
    }
    return cnt;
}

bool linkedlist::trungSo(int x)
{
    element *tmp = this->head;
    while (tmp != nullptr)
    {
        if (tmp->getData() == x)
        {
            cout << "Da co so nay trong danh sach: ";
            return false;
        }
        tmp = tmp->Getpointer();
    }
    return true;
}

// // Liệt kê siêu thị có số lượng nhân viên từ 30 đến 50
// void nhanVien()
// {
//     element *temp = head;
//     while (temp)
//     {
//         if (temp->getSl() >= 30 && temp->getSl() <= 50)
//         {
//             cout << "- " << temp->getName() << endl;
//         }
//         temp = temp->getPointer();
//     }
// }

// // Xóa siêu thị có doanh thu < 1 tỷ và đã hoạt động trên 5 năm
// void xoa(int nam)
// {
//     element *temp = head;
//     element *prev = nullptr;
//     while (temp)
//     {
//         if ((nam - temp->getNamThanhLap() > 5) && temp->getDT() < 1000)
//         {
//             if (prev)
//             {
//                 prev->setPointer(temp->getPointer());
//             }
//             else
//             {
//                 head = temp->getPointer();
//             }
//             delete temp;
//             temp = (prev) ? prev->getPointer() : head;
//             count--;
//         }
//         else
//         {
//             prev = temp;
//             temp = temp->getPointer();
//         }
//     }
// }

// void danhMuc()
// {
//     element *temp = head;
//     while (temp)
//     {
//         auto categories = temp->getSP();
//         if (find(categories.begin(), categories.end(), "Thực phẩm") != categories.end() &&
//             find(categories.begin(), categories.end(), "Đồ gia dụng") != categories.end())
//         {
//             cout << "- " << temp->getName() << endl;
//         }
//         temp = temp->getPointer();
//     }
// }