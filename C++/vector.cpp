#include <iostream>
#include <optional>

class Vector
{
private:
    int size{0};
    int cap{1};
    int *arr;

private:
    void my_realloc(int step = 2)
    {
        int *tmp = arr;
        arr = new int(size * step);

        for (size_t i = 0; i < size; i++)
        {
            arr[i] = tmp[i];
        }
        delete tmp;
    }

    void swap(int &x, int &y)
    {
        int tmp = x;
        x = y;
        y = tmp;
    }

public:
    int get_size() { return size; }
    int get_capacity() { return cap; }
    void pop() { --size; };
    bool is_empty() { return size; }

    std::optional<int> erase(int index)
    {
        if (index >= size)
            return std::nullopt;

        for (int i = index; i < size; i++)
        {
            swap(arr[i], arr[i + 1]);
        }
        --size;
        return 1;
    }

    std::optional<int> at(int val)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == val)
                return i;
        }
        return std::nullopt;
    }

    void print_arr()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void push_back(int val)
    {
        if (size == cap)
        {
            cap *= 2;
            my_realloc();
        }

        arr[size] = val;
        size++;
    }

public:
    Vector() : size(0), cap(1), arr{new int} {}
    Vector(const std::initializer_list<int> &args) : size(0), cap(1), arr{new int}
    {
        for (const int val : args)
        {
            push_back(val);
        }
    }
    ~Vector()
    {
        delete arr;
    };
};

int main()
{
    Vector vec{1, 2, 3, 4};
    vec.push_back(10);
    vec.print_arr();
    vec.push_back(5);
    vec.print_arr();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.pop();
    vec.push_back(5);
    vec.print_arr();

    if (vec.erase(4) == std::nullopt)
    {
        std::cout << "wrong index" << std::endl;
    }
    vec.print_arr();

    if (std::optional<int> index = vec.at(22))
    {
        std::cout << index.value() << std::endl;
    }
    else
        std::cout << "unvalid value" << std::endl;
}