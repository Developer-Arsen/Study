// // EmptyClass.cpp
#include <iostream>
#include <memory>

class a
{
public:
    a()
    {
        std::cout << "a ctor" << std::endl;
    }
    ~a()
    {
        std::cout << "a dtor" << std::endl;
    }
};

class EmptyClass
{
public:
    EmptyClass()
    {
        std::cout << "EmptyClass ctor" << std::endl;
    }
    ~EmptyClass()
    {
        std::cout << "EmptyClass dtor" << std::endl;
    }

public:
    void go()
    {
        std::cout << "this is go func" << std::endl;
    }

private:
    a obj;
};

void doubleintstacks(int (&arr)[2])
{
    std::unique_ptr ptr{std::make_unique<int>(5)};
    std::cout << *ptr << std::endl;

    auto ptr1 = std::move(ptr);

    *ptr1 = 10;
    std::cout << *ptr1 << std::endl;

    // int * a {new int};
    // *a = 4;

    // auto ptr {std::make_shared<int>(5)};
    // std::cout << "as" << std:: endl;

    // auto ptr1 = ptr;
    // *ptr1  = 10;
    // std::cout << *ptr<< std:: endl;

    // std::cout << "ref count is: " << ptr.use_count() << std:: endl;
}

[[nodiscard]] int *my_alloc([[maybe_unused]] int value)
{
    return new int{1};
}

void my_free(int *p)
{
    delete p;
}

void my_close(FILE *p)
{
    if (p == nullptr)
        return;
    fclose(p);
    std::cout << "file is closed" << std::endl;
}

void foo(int num) {
    std::cout << "num" << std::endl;
}

void foo(void * ptr) {
    std::cout << "ptr" << std::endl;
}

void foo(bool bl) {
    std::cout << "bl" << std::endl;
}


int main()
{
    my_alloc(3);

    // int arr[] {1,2};
    // doubleintstacks(arr);

    // std::unique_ptr<int , decltype(&my_free)> smartptr {my_alloc(42), my_free};
    // std::shared_ptr<int> sharedptr {my_alloc(42), my_free};

    // FILE * f { fopen("file.txt", "w")};
    // std::shared_ptr<FILE> p {f, my_close};

    // if (p == nullptr) {
    //     std::cerr << "failed to open file" << std::endl;
    // } else std::cout << "file opened" << std::endl;

    // fwrite("buff", 4, 1, f);

    // bool is = 0.1 + 0.2 == 0.3;

    // int * values {new int[10]};

    // delete [] values;
    // EmptyClass obj;
    // int * ptr {new (std::nothrow) int};
    // int size = 10;
    // EmptyClass * ptr {new(std::nothrow) EmptyClass[10]};
    // int * ptr {new int[size] {1,23,4}};

    // for (size_t i = 0; i < size; i++)
    // {
    //     std::cout << ptr[i] << std::endl;
    // }
    // delete [] ptr;

    foo(0);
    foo(nullptr);
    foo(true);

    return 0;
}
