
#ifndef VECTOR_H_
#define VECTOR_H_

#include <initializer_list>

template <typename T>
class Vector
{
    T * m_arr;
    int m_size;
    int m_capacity;

public:
    Vector();
    Vector(int size);
    Vector(int size, T val);
    Vector(const Vector&);
    Vector(Vector&&);
    Vector(std::initializer_list<T>);

    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    T operator[](int);

    void push_back(T);
    void pop();
    bool is_empty() const;
    int size() const;
    int at(T) const;

    ~Vector();
};


#include "vector.tpp"
#endif

 
// returns the associated allocator
// (public member function)
// Element access
// at
 
// access specified element with bounds checking
// (public member function)
// operator[]
 
// access specified element
// (public member function)
// front
 
// access the first element
// (public member function)
// back
 
// access the last element
// (public member function)
// data
 
// direct access to the underlying contiguous storage
// (public member function)
// Iterators
// begin
// cbegin
  
// (C++11)
 
// returns an iterator to the beginning
// (public member function)
// end
// cend
  
// (C++11)
 
// returns an iterator to the end
// (public member function)
// rbegin
// crbegin
  
// (C++11)
 
// returns a reverse iterator to the beginning
// (public member function)
// rend
// crend
  
// (C++11)
 
// returns a reverse iterator to the end
// (public member function)
// Capacity
// empty
 
// checks whether the container is empty
// (public member function)
// size
 
// returns the number of elements
// (public member function)
// max_size
 
// returns the maximum possible number of elements
// (public member function)
// reserve
 
// reserves storage
// (public member function)
// capacity
 
// returns the number of elements that can be held in currently allocated storage
// (public member function)
// shrink_to_fit
  
// (DR*)
 
// reduces memory usage by freeing unused memory
// (public member function)
// Modifiers
// clear
 
// clears the contents
// (public member function)
// insert
 
// inserts elements
// (public member function)
// insert_range
  
// (C++23)
 
// inserts a range of elements
// (public member function)
// emplace
  
// (C++11)
 
// constructs element in-place
// (public member function)
// erase
 
// erases elements
// (public member function)
// push_back
 
// adds an element to the end
// (public member function)
// emplace_back
  
// (C++11)
 
// constructs an element in-place at the end
// (public member function)
// append_range
  
// (C++23)
 
// adds a range of elements to the end
// (public member function)
// pop_back
 
// removes the last element
// (public member function)
// resize
 
// changes the number of elements stored
// (public member function)
// swap
 
// swaps the contents
// (public member function)
// Non-member functions
// operator==
// operator!=
// operator<
// operator<=
// operator>
// operator>=
// operator<=>
  
// (removed in C++20)
// (removed in C++20)
// (removed in C++20)
// (removed in C++20)
// (removed in C++20)
// (C++20)
 
// lexicographically compares the values of two vectors
// (function template)
// std::swap(std::vector)
 
// specializes the std::swap algorithm
// (function template)
// erase(std::vector)
// erase_if(std::vector)
  
// (C++20)
 
// erases all elements satisfying specific criteria
// (function template)