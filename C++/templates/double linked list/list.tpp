#include <iostream>
#include <initializer_list>
#include "list.hpp"

template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
}

template<typename T>
List<T>::List(const List<T>& list) {
    if (list.head) {
        head = new Node { list.head->val, nullptr, nullptr };

        Node * tmphead = list.head->next;
        Node * prev = head;
        while (tmphead)
        {
            Node * tmp = new Node { tmphead->val, nullptr, prev };
            prev->next = tmp;            
            prev = tmp;
            tmphead = tmphead->next;
        }

        tail = prev;
        
    } else {
        head = nullptr;
        tail = nullptr;
    }
}


template<typename T>
List<T>::List(List<T>&& list) {
    head = list.head;
    tail = list.tail;

    list.head = nullptr;
    list.tail = nullptr;
}

template<typename T>
List<T>::List(std::initializer_list<T> args) {
    if (args.size()) {
        auto iter = args.begin();
        head = new Node { *iter++, nullptr, nullptr };

        Node * prev = head;
        for (; iter != args.end(); ++iter) {
            Node * tmp = new Node { *iter, nullptr, prev };
            prev->next = tmp;
            prev = tmp;
        }
        tail = prev;
        
    } else {
        head = nullptr;
        tail = nullptr;
    }
}

template<typename T>
void List<T>::push_front(const T& val) {
    Node * tmp = new Node{val, head, nullptr};
    head = tmp;
}


template<typename T>
void List<T>::push_back(const T& val) {
    Node * tmp = new Node{val, nullptr, tail};
    tail->next = tmp;
    tail = tmp;
}

template<typename T>
template<typename... Args>
void List<T>::emplace_front(Args&&... args) {
    Node * tmp = new Node { T(args...), head, nullptr };
    head = tmp;
}

// template<typename T>
// template<typename... Args>
// void List<T>::emplace_back(Args&&... args) {
//     Node * node = new Node (T(...args), nullptr, tail);
//     tail -> next = node;
//     tail = node;
// } 

template<typename T>
List<T>::~List() {
    Node * tmp = head;
    while (head)
    {
        
        head = head->next;
        delete tmp;
        tmp = head;
    }
}