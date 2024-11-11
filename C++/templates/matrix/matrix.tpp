#include <initializer_list>
#include <vector>
#include <iostream>

#include "matrix.hpp"

template<typename T>
Matrix<T>::Matrix() {
    m_maxSize = 100;
}

template<typename T>
Matrix<T>::Matrix(T val) {
    push(val);
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other) {
    for (int i = 0; i < other.m_arr.size(); i++) 
    {
        push(other.m_arr[i]);
    }
}

template<typename T>
Matrix<T>::Matrix(Matrix&& other) {
    m_arr = other.m_arr;
    m_maxSize = other.m_maxSize;
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<T> list) {
    for (auto& val : list) {
        m_arr.push_back(val);
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < other.m_arr.size(); i++) 
    {
        push(other.m_arr[i]);
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) {
    if (this == &other) {
        return *this;
    }
    m_arr = other.m_arr;
    m_maxSize = other.m_maxSize;
}
