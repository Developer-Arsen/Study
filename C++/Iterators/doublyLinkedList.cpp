#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

template <typename IT>
class reverse_iterator_class;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    using value_type = T;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++size;
    }

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    void pop_front() {
        if (!head) throw std::underflow_error("List is empty.");
        Node<T>* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        --size;
    }

    void pop_back() {
        if (!tail) throw std::underflow_error("List is empty.");
        Node<T>* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        --size;
    } 

    T front() const {
        if (!head) throw std::underflow_error("List is empty.");
        return head->data;
    }

    T back() const {
        if (!tail) throw std::underflow_error("List is empty.");
        return tail->data;
    }

    bool empty() const {
        return size == 0;
    }

    size_t get_size() const {
        return size;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void display() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    class const_iterator {
    protected:
        Node<T> *ptr;

        const_iterator(Node<T> *_ptr) : ptr{_ptr} { }
    public:
        friend class DoublyLinkedList;

        const_iterator() : ptr{nullptr} { }

        using iterator_category = decltype(std::forward_iterator_tag());
        using value_type = T;
        using reference = const T&;
        using pointer = const T*;
        using difference_type = std::ptrdiff_t;

        reference operator*() const {
            return this->ptr->data;
        }
        pointer operator->() const {
            return &(**(this->ptr));
        }
        const_iterator &operator++() {
            if (this->ptr) ptr = ptr->next;
            return *this;
        }
        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        const_iterator &operator--() {
            if (this->ptr) ptr = ptr->prev;
            return *this;
        }
        const_iterator operator--(int) {
            const_iterator tmp = *this;
            --(*this);
            return tmp;
        }
        bool operator==(const const_iterator &other) const {
            return this->ptr == other.ptr;
        }
        bool operator!=(const const_iterator &other) const {
            return !(operator==(other));
        }
    };

    class iterator : public const_iterator {
    private:
        iterator(Node<T> *_ptr) : const_iterator(_ptr) { }
    public:
        friend class DoublyLinkedList;

        using iterator_category = typename const_iterator::iterator_category;
        using value_type = typename const_iterator::value_type;
        using reference = typename const_iterator::reference;
        using pointer = typename const_iterator::pointer;
        using difference_type = typename const_iterator::difference_type;

        iterator() : const_iterator() { }

        reference operator*() {
            return this->ptr->data;
        }
        pointer operator->() {
            return &(**(this->ptr));
        }
        bool operator==(const iterator &other) {
            return this->ptr == other.ptr;
        }
        bool operator!=(const iterator &other)  {
            return !(operator==(other));
        }
        iterator &operator++() {
            if (this->ptr) this->ptr = this->ptr->next;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        iterator &operator--() {
            if (this->ptr) this->ptr = this->ptr->prev;
            return *this;
        }
        iterator operator--(int) {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }
    };

    const_iterator cbegin() const {
        return const_iterator(head);
    }
    const_iterator cend() const {
        return const_iterator(nullptr);
    }
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    }

    using reverse_iterator = reverse_iterator_class<iterator>;
    using const_reverse_iterator = reverse_iterator_class<const_iterator>;

    reverse_iterator rbegin() {
        return reverse_iterator(iterator(tail));
    }

    reverse_iterator rend() {
        return reverse_iterator(iterator(nullptr));
    }

   const_reverse_iterator crbegin() const {
        return const_reverse_iterator(const_iterator(tail));
    }

   const_reverse_iterator crend() const {
        return const_reverse_iterator(const_iterator(nullptr));
    }
};


template <typename IT>
class reverse_iterator_class {
private:
    IT iterator_obj;
public:
    using value_type = typename IT::value_type;
    using reference = typename IT::reference;
    using pointer = typename IT::pointer;

    reverse_iterator_class(IT it) : iterator_obj{it} { }

    reference operator*() {
        // auto tmp = iterator_obj;
        // --tmp;
        // return *tmp;
        return *iterator_obj;
    }
    pointer operator->() {
        return &operator*();
    }
    reverse_iterator_class &operator++() {
        --iterator_obj;
        return *this;
    }
    reverse_iterator_class operator++(int) {
        return iterator_obj++;
    }
    reverse_iterator_class &operator--() {
        ++iterator_obj;
        return *this;
    }
    reverse_iterator_class operator--(int) {
        return iterator_obj--;
    }
    bool operator==(const reverse_iterator_class &other) {
        return iterator_obj == other.iterator_obj;
    }
    bool operator!=(const reverse_iterator_class &other) {
        return iterator_obj != other.iterator_obj;
    }
    IT base() const {
        return iterator_obj;
    }
};

template <typename Cont>
class Back_insert_iterator {
private:
    Cont &cont;
public:
    Back_insert_iterator(Cont &cont_) : cont{cont_} { }

    Back_insert_iterator &operator*() {
        return *this;
    }
    Back_insert_iterator &operator++() {
        return *this;
    }
    Back_insert_iterator &operator++(int) {
        return *this;
    }
    Back_insert_iterator &operator=(const typename Cont::value_type &val) {
        cont.push_back(val);
        return *this;
    }
};

template <typename Cont>
Back_insert_iterator<Cont> Back_inserter(Cont &cont) {
    return Back_insert_iterator<Cont>(cont);
}

int main() {
    DoublyLinkedList<int> list;

    list.push_back(10); // 10 20 30 40 50 60
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);
    list.push_back(60);
    list.push_back(70);

    // std::cout << "Forward traversal: ";
    // for (auto it = list.begin(); it != list.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";

    // std::cout << "Reverse traversal: ";
    // for (auto it = list.rbegin(); it != list.rend(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";

    // std::cout << "Const reverse traversal: ";
    // for (auto it = list.crbegin(); it != list.crend(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << "\n";

    // DoublyLinkedList<int>::iterator it = std::find(list.begin(), list.end(), 40);

    // std::cout << *it << std::endl;

    // DoublyLinkedList<int>::reverse_iterator rit(it);

    // std::cout << *rit << std::endl;

    auto it = Back_inserter(list);

    *it = 40;
    it = 50;
    ++it = 60;
    *(++it) = 70;

    for (auto i = list.rbegin(); i != list.rend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    

    return 0;
}