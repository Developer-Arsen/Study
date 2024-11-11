#include "vector.hpp"
#include <iostream>
#include <initializer_list>

template <typename T>
Vector<T>::Vector()
{
    m_size = 0;
    m_capacity = 0;
    m_arr = nullptr;
}

template <typename T>
Vector<T>::Vector(int size)
{
    m_arr = new T[size];
    m_capacity = size;
}

template <typename T>
Vector<T>::Vector(int size, T val)
{
    for (int i = 0; i < size; i++)
    {
        push_back(i);
    }
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
    const int size = other.size();

    m_arr = new T[size];
    m_size = size;
    m_capacity = m_size * 2;
    for (int i = 0; i < other.size(); i++)
    {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector && other)
{
    m_arr = other.m_arr;
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    other.m_arr = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> list)
{
    m_size = list.size();
    m_arr = new T[m_size];

    int i = 0;
    for (auto& val : list) {
        m_arr[i++] = val;
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this == &other) {
        return *this;
    }
    const int size = other.size();

    m_arr = new T[size];
    m_size = size;
    m_capacity = m_size * 2;
    for (int i = 0; i < other.size(); i++)
    {
        m_arr[i] = other.m_arr[i];
    }

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
    delete [] m_arr;

    m_arr = other.arr;
    m_size = other.size;
    m_capacity = other.capacity;

    other.arr = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;
}

template<typename T>
T Vector<T>::operator[](int index) {
    return m_arr[index];
}

template <typename T>
Vector<T>::~Vector()
{
    if (m_size) {
        delete [] m_arr;
    }
}

template <typename T>
int Vector<T>::size() const
{
    return m_size;
}

template <typename T>
void Vector<T>::push_back(T val) 
{
    if (m_size == m_capacity) {
        m_capacity = m_size * 2;

        T * old = m_arr;
        m_arr = new T[m_capacity];

        for (int i = 0 ; i < m_size; ++i) {
            m_arr[i] = old[i];
        }
    }

    m_arr[m_size++] = val;
}

template <typename T>
void Vector<T>::pop()
{
    --m_size;
}

template <typename T>
bool Vector<T>::is_empty() const
{
    return m_size == 0;
}

template <typename T>
int Vector<T>::at(T val) const
{
    for (int i = 0; i < m_size; ++i) {
        if (m_arr[i] == val) return i;
    }
    return -1;
}
