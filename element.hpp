// file node.hpp

#ifndef element_hpp
#define element_hpp

class element
{
private:
    int data;
    element *pointer;

public:
    element()
    {
        data = 0;
        pointer = nullptr;
    };
    element(int n)
    {
        data = n;
        pointer = nullptr;
    };
    virtual ~element() {};
    int getData() { return data; };
    void setData(int n) { data = n; };
    element *Getpointer() { return pointer; };
    void Setpointer(element *moi) { pointer = moi; };
};

#endif