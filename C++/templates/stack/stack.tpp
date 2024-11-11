#include <initializer_list>
#include <vector>
#include <iostream>

#include "stack.hpp"

template<typename T>
Stack<T>::Stack() {
    m_maxSize = 100;
}

template<typename T>
Stack<T>::Stack(T val) {
    push(val);
}

template<typename T>
Stack<T>::Stack(const Stack& other) {
    for (int i = 0; i < other.m_arr.size(); i++) 
    {
        push(other.m_arr[i]);
    }
}

template<typename T>
Stack<T>::Stack(Stack&& other) {
    m_arr = other.m_arr;
    m_maxSize = other.m_maxSize;
}

template<typename T>
Stack<T>::Stack(std::initializer_list<T> list) {
    for (auto& val : list) {
        m_arr.push_back(val);
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < other.m_arr.size(); i++) 
    {
        push(other.m_arr[i]);
    }
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& other) {
    if (this == &other) {
        return *this;
    }
    m_arr = other.m_arr;
    m_maxSize = other.m_maxSize;
}

template<typename T>
void Stack<T>::push(T val) {
    if (m_arr.size() == m_maxSize) {
        throw std::out_of_range("Index out of range");
    } else {
        m_arr.push_back(val);
    }
}

template<typename T>
void Stack<T>::pop() {
    if (m_arr.size() <= 0) {
        throw std::out_of_range("Index out of range");
    } else {
        m_arr.pop_back();
    }
}

template<typename T>
T& Stack<T>::top() {
    if (m_arr.size() <= 0) {
        throw std::out_of_range("Index out of range");
    } else {
        return m_arr[m_arr.size() - 1];
    }
}

template<typename T>
bool Stack<T>::isEmpty() {
    return m_arr.size() == 0;
}

