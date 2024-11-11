#ifndef STACK_H_
#define STACK_H_

#include <initializer_list>
#include <vector>

template<typename T>
class Stack {
    std::vector<T> m_arr;
    int m_maxSize;
    public:
        Stack();
        Stack(T);
        Stack(const Stack&);
        Stack(Stack&&);
        Stack(std::initializer_list<T>);

        Stack& operator=(const Stack&);
        Stack& operator=(Stack&&);

        void push(T val);
        void pop();
        T& top();
        bool isEmpty();
};

#include "stack.tpp"

#endif