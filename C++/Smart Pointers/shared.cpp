#include <memory>
#include <iostream>

struct container {
    int shared_count;
    int weak_count;
};

class shared_ptr
{
private:
    int *obj;
    container* cont;

public:
    shared_ptr() : obj(nullptr), cont(new container()) {
        std::cout << "default " << cont->shared_count << "  " << cont ->weak_count << std::endl;
    }
    shared_ptr(int *ptr)
    {
        obj = ptr;
        cont = new container();
        cont->shared_count = 1;
        cont->weak_count = 0;
        
        std::cout << "parametr " << cont->shared_count << "  " << cont ->weak_count << std::endl;
    }
    shared_ptr(const shared_ptr &ptr)
    {
        obj = ptr.obj;
        cont = ptr.cont;
        cont->shared_count++;

        std::cout << "copy " << cont->shared_count << "  " << cont ->weak_count << std::endl;
    }
    shared_ptr(const shared_ptr &&ptr) {
        obj = ptr.obj;
        cont = ptr.cont;

        std::cout << "move " << cont->shared_count << "  " << cont ->weak_count << std::endl;
    }

    shared_ptr& operator=(shared_ptr& other) {
        obj = other.obj;
        cont = other.cont;
        cont->weak_count++;

        std::cout << "operator = copy " << cont->shared_count << "  " << cont ->weak_count << std::endl;
        return *this;
    }

    shared_ptr& operator=(shared_ptr&& other) {
        obj = other.obj;
        cont = other.cont;

        std::cout << "operator = move " << cont->shared_count << "  " << cont ->weak_count << std::endl;
        return *this;
    }

    int operator*() {
        return *obj;
    }

    int* operator->() {
        return obj;
    }

    ~shared_ptr() {
        std::cout << "destructor " << cont->shared_count << "  " << cont ->weak_count << std::endl;

        cont->shared_count--;
        if (cont->shared_count == 0) {
            delete obj;
            obj = nullptr;

            if (cont->weak_count == 0) {
                delete cont;
                cont = nullptr;
            }

        }
    }
};

int main()
{

    int * x = new int{10};
    shared_ptr ptr(x);
    shared_ptr ptr2(ptr);
    shared_ptr ptr3(std::move(ptr));
}