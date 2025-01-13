#include <iostream>
// #include "linkedlist.hpp"
#include "stack.hpp"
#include "queue.hpp"
// #include <cmath>
#include <vector>
#include <cstdlib> // Needed for rand() and srand()
#include <ctime>
using namespace std;

// void tachList(linkedlist *listNho, linkedlist *listLon, int x, linkedlist *danhSach)
// {
//     element *tmp = danhSach->getHead();
//     element *moi;

//     while (tmp != nullptr)
//     {
//         moi = new element(tmp->getData()); // Tạo element mới.

//         if (tmp->getData() >= x)
//         {
//             listLon->InsertFirst(moi); // Thêm vào danh sách lớn
//         }
//         else
//         {
//             listNho->InsertFirst(moi); // Thêm vào danh sách nhỏ
//         }

//         tmp = tmp->Getpointer();
//     }
// }

void deBi(Stack *&bi, int dec)
{
    while (dec)
    {
        bi->PushStack(dec % 2);
        dec /= 2;
    }
}

struct toaDo
{
    int x;
    int y;
};

void mangNgauNhien(vector<vector<int>> &v)
{
    srand(time(0));
    for (auto &i : v)
    {
        for (auto &it : i)
        {
            it = rand() % 2;
        }
    }
}

int check(vector<vector<int>> v, int x, int y, int n, int m, int tham)
{
    if (x >= n || x < 0)
        return 0;
    if (y >= m || y < 0)
        return 0;
    if (tham == 1 || v[x][y] == 0)
    {
        return 0;
    }
    return 1;
}

int timDuongDi(vector<vector<int>> v, toaDo toaDoDau, toaDo toaDoCuoi)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> tham(m, vector<int>(n, 0)); // mảng kiểm tra tọa độ đã được kiểm tra trước đó hay chưa.
    int h[] = {1, 0, -1, 0};
    int k[] = {0, 1, 0, -1};
    int x, y, xx, yy;
    Queue *doi1 = new Queue();
    Queue *doi2 = new Queue();
    doi1->pushBack(toaDoDau.x);
    doi2->pushBack(toaDoDau.y);
    tham[toaDoDau.x][toaDoDau.y] = 1; // danh dau dim bat dau da duoc tham
    int first = 0, last = 1;
    while (doi1->getN() != 0)
    {
        x = doi1->popFront();
        y = doi2->popFront();
        for (int i = 0; i < 4; ++i)
        {
            xx = x + h[i];
            yy = y + k[i];
            if (xx == toaDoCuoi.x && yy == toaDoCuoi.y)
                return 1;
            if (check(v, xx, yy, n, m, tham[xx][yy]))
            {
                doi1->pushBack(xx);
                doi2->pushBack(yy);
                tham[xx][yy] = 1;
            }
        }
    }
    return 0;
}

int check(int v, int xx, int yy, int n, int m, int tham)
{
    if (xx >= n || yy >= m || xx < 0 || yy < 0)
        return 0;
    if (tham == 1 || v == 0)
        return 0;
    return 1;
}

int bfs(vector<vector<int>> v, toaDo dau, toaDo cuoi)
{
    int n = v.size();                               // so luong dong
    int m = v[0].size();                            // so luong hang
    vector<vector<int>> tham(n, vector<int>(m, 0)); // gan cho mang tham co gia tri la 0
    int x, y, xx, yy;
    Queue *doi1 = new Queue(dau.x);
    Queue *doi2 = new Queue(dau.y);
    int k[] = {1, 0, -1, 0};
    int h[] = {0, -1, 0, 1};
    tham[dau.x][dau.y] = 1;
    while (doi1->getN() != 0)
    {
        x = doi1->popFront();
        y = doi2->popFront();
        for (int i = 0; i < 4; ++i)
        {
            xx = x + k[i];
            yy = y + h[i];
            if (xx == cuoi.x && yy == cuoi.y)
            {
                return 1;
            }
            if (check(v[xx][yy], xx, yy, n, m, tham[xx][yy]))
            {
                doi1->pushBack(xx);
                doi2->pushBack(yy);
                tham[xx][yy] = 1;
            }
        }
    }
    return 0;
}

void inVector(vector<vector<int>> v)
{
    for (auto it : v)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int toaTauDiChuyenQ(int a[], int b[], int n, Queue *duongDi)
{
    Queue *tmp = new Queue();
    int ia = 0;
    for (int i = 0; i < n; ++i)
    {
        while (1)
        {
            if (ia < n)
            {
                if (b[i] == a[ia])
                {
                    duongDi->pushBack(13); // 13 (A->C)
                    ia++;
                    break;
                }
                else if (b[i] > a[ia])
                {
                    tmp->pushBack(a[ia++]);
                    continue;
                }
            }
            if (tmp->getN() != 0 && b[i] == tmp->getData())
            {
                duongDi->pushBack(23); // 12 (A->B)
                tmp->popFront();
                break;
            }
            if (ia < n && b[i] > a[ia])
            {
                tmp->pushBack(a[ia++]);
                continue;
            }
            return 0;
        }
    }
    return 1;
}

int toaTauDiChuyenS(int a[], int b[], int n, Queue *duongDi)
{
    Stack *tmp = new Stack();
    int ia = 0;
    for (int i = 0; i < n; ++i)
    {
        while (1)
        {
            if (ia < n)
            {
                if (b[i] == a[ia])
                {
                    duongDi->pushBack(13); // 13 (A->C)
                    ia++;
                    break;
                }
                else if (b[i] > a[ia])
                {
                    tmp->PushStack(a[ia++]);
                    continue;
                }
            }
            if (tmp->getN() != 0 && b[i] == tmp->getData())
            {
                duongDi->pushBack(23); // 12 (A->B)
                tmp->PopStack();
                break;
            }
            return 0;
        }
    }
    return 1;
}

// int dichuyen(Queue *ans, Queue *qs, Queue *duongDi){
//     Queue *tmp = new Queue();
//     while(ans->getN() && ){
//         if(ans->getData() == qs->getData()){
//             duongDi->pushBack(13);
//             ans->popFront();
//         }
//         else if(ans->getData() > qs->getData()){
//             tmp->pushBack(qs->popFront());
//         }
//         else {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main()
// {
//     Queue *ans = new Queue();
//     Queue *qs = new Queue();
//     int n;
//     cout << "Nhap so luong toa tau: ";
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; ++i)
//     {
//         a[i] = i + 1;
//         qs->pushBack(i + 1);
//     }
//     int b[n];
//     cout << "Nhap thu tu o vi tri dich: ";
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> b[i];
//         while (b[i] > n || b[i] <= 0)
//         {
//             cout << "Nhap lai so cua toa tau: ";
//             cin >> b[i];
//         }
//         ans->pushBack(b[i]);
//     }
//     Queue *duongDi = new Queue();
//     string chuoi = toaTauDiChuyenQ(a, b, n, duongDi) ? "Di duoc" : "Khong di duoc";
//     cout << chuoi << endl;
//     chuoi = toaTauDiChuyenS(a, b, n, duongDi) ? "Di duoc" : "Khong di duoc";
//     cout << chuoi << endl;

//     return 0;
// }

int main()
{
    // Stack *s = new Stack();
    // s->PushStack(5);
    // s->PushStack(10);
    // s->PushStack(554);
    // s->in(); // in từ đầu đến cuối mảng
    // cout << s->PopStack() << " ";
    // cout << s->PopStack() << " ";
    // cout << s->PopStack() << " ";
    // cout << s->PopStack() << " \n";
    // Queue *q = new Queue();
    // q->EnQueue(10);
    // q->EnQueue(56);
    // q->EnQueue(2486);
    // q->in();
    // cout << q->DeQueue() << " ";
    // cout << q->DeQueue() << " ";
    // cout << q->DeQueue() << " ";
    // cout << q->DeQueue() << " " << endl;
    // Stack *binary = new Stack();
    // int dec = 20;
    // deBi(binary, dec);
    // cout << binary->getN() << endl;
    // int cnt = binary->getN();
    // for (int i = 0; i < cnt; ++i)
    // {
    //     cout << binary->PopStack() << " ";
    // }

    int n = 6;
    int m = 6;
    vector<vector<int>> v(n, vector<int>(m, 0));

    mangNgauNhien(v);
    inVector(v);

    toaDo toaDoDau;
    toaDo toaDoCuoi;

    int di = 1;
    while (di)
    {
        cout << "Nhap toa do diem bat dau:\n";
        cout << "x = ";
        cin >> toaDoDau.x;
        cout << "y = ";
        cin >> toaDoDau.y;

        cout << "Nhap toa do diem ket thuc:\n";
        cout << "x = ";
        cin >> toaDoCuoi.x;
        cout << "y = ";
        cin >> toaDoCuoi.y;

        // Kiểm tra tọa độ có nằm trong giới hạn không
        if (toaDoDau.x < 0 || toaDoDau.x >= n || toaDoDau.y < 0 || toaDoDau.y >= m ||
            toaDoCuoi.x < 0 || toaDoCuoi.x >= n || toaDoCuoi.y < 0 || toaDoCuoi.y >= m)
        {
            cout << "Toa do khong hop le. Vui long nhap lai.\n";
        }
        else if (toaDoDau.x == toaDoCuoi.x && toaDoDau.y == toaDoCuoi.y)
        {
            cout << "Hai toa do trung nhau.\n";
        }
        else if (v[toaDoDau.x][toaDoDau.y] == 0 || v[toaDoCuoi.x][toaDoCuoi.y] == 0)
        {
            cout << "Khong the di den cuoi duoc.\n";
        }
        else if (bfs(v, toaDoDau, toaDoCuoi))
        {
            cout << "Co the di chuyen den cuoi.\n";
        }
        else
        {
            cout << "Khong the di chuyen den cuoi.\n";
        }

        cout << "Ban con muon tiep tuc di chuyen khong?\n";
        cout << "0. Nghi\n1. Di tiep\n";
        cin >> di;

        // Kiểm tra giá trị của di
        while (di != 0 && di != 1)
        {
            cout << "Gia tri khong hop le. Vui long nhap 0 hoac 1: ";
            cin >> di;
        }
    }
}

// int main()
// {
//     linkedlist *danhSach = new linkedlist();
//     element *moi;
//     moi = new element(4);
//     danhSach->pushFront(moi); // Thêm vào đầu danh sách
//     moi = new element(2);
//     danhSach->pushFront(moi);
//     moi = new element(1);
//     danhSach->pushFront(moi);
//     moi = new element(6);
//     danhSach->pushBack(moi); // Thêm vào cuối danh sách
//     moi = new element(7);
//     danhSach->pushBack(moi);
//     element *p = new element(8);
//     danhSach->pushBack(p);
//     moi = new element(9);
//     danhSach->chenP(moi, p);
//     danhSach->popFront();
//     danhSach->popBack();
//     moi = new element(10);
//     danhSach->pushBack(moi);
//     danhSach->duyet();
//     danhSach->xoaP(moi); // Xoa element có dữ liệu là 10
//     danhSach->duyet();
//     int tong = danhSach->sumList();
//     cout << "Tong cua danh sach la: " << tong << endl;
//     int max = danhSach->maxList();
//     cout << "So nguyen lon nhat trong danh sach la: " << max << endl;
//     int nto = danhSach->countPrime();
//     cout << "So luong so nguyen to co trong danh sach la: " << nto << endl;
//     array *listNho = new array();
//     array *listLon = new array();
//     int x = 3;
//     cout << "Nhap gia tri cua x: ";
//     cin >> x;
//     tachList(listNho, listLon, x, danhSach);
//     danhSach->duyet();
//     cout << "Danh sach nho hon " << x << " la: ";
//     listNho->duyet();
//     cout << "Danh sach lon hon hoac bang " << x << " la: ";
//     listLon->duyet();
//     danhSach->removeAll();
//     danhSach->duyet();
// }

// cd "d:\linkedList\" ; if ($?) { g++ *.cpp -o ll } ; if ($?) { .\ll }
