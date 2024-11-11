#ifndef MATRIX_H_
#define MATRIX_H_

#include <initializer_list>
#include <vector>

template<typename T>
class Matrix {
    std::vector<T> m_arr;

    public:
        Matrix();
        Matrix(T);
        Matrix(const Matrix&);
        Matrix(Matrix&&);
        Matrix(std::initializer_list<T>);

        Matrix& operator=(const Matrix&);
        Matrix& operator=(Matrix&&);

};

#include "matrix.tpp"

#endif