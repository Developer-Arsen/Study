#include <iostream>

using std::cout;
using std::endl;

class foo
{

public:
    virtual void bar()
    {
        cout << "foo i functiona" << endl;
    }

    long ars{10};
};

class boo : public foo
{
public:
    void bar()
    {
        cout << "boo i functiona" << endl;
    }

    long ars{100};
};

void printFunctionAddress(void (*func_ptr)())
{
    cout << "Function address: " << reinterpret_cast<void *>(func_ptr) << endl;
}

int main()
{

    foo *foo1 = new foo();

    long *vptr = reinterpret_cast<long *>(&(*foo1));
    vptr = reinterpret_cast<long *>(*(vptr));
    auto fptr = reinterpret_cast<void (*)(foo *)>(vptr[0]);
    fptr(foo1);
    // cout << "Address of foo::bar: " << endl;
    // printFunctionAddress(reinterpret_cast<void(*)()>(&foo::bar));
    // cout << fptr << endl;
    // void (*fptr)() = reinterpret_cast<void(*)()>(*(vptr + 3));
    // cout << fptr << endl;
    // fptr();
}