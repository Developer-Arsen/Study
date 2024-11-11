#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <initializer_list>

template <typename T>
class List
{
    struct Node
    {
        T val;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;

public:
    List();
    List(std::initializer_list<T>);
    List(const List<T>&);
    List(List<T>&&);
    ~List();

    template<typename... Args>
    void emplace_front(Args&&...);

    // template<typename... Args>
    // void emplace_back(Args&&...);
    
    void push_front(const T&);
    void push_back(const T&);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const List<U> &);
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &obj)
{
    typename List<T>::Node *node = obj.head;

    os << "[";

    while (node != nullptr)
    {
        os << node->val;
        if (node->next)
        {
            os << ",";
        }
        node = node->next;
    }

    os << "]";
    return os;
}

#include "list.tpp"
#endif