#include <iostream>
#include <type_traits>

template<typename T>
class Vector {

public:
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using pointer = value_type*;
        using size_type = size_t;
        using const_reference = const reference;

    class const_interator {
        public:
            const_interator() : ptr{nullptr} {}
            const_interator(const const_interator& rhv) { 
                ptr = rhv.ptr;
            } 
            const_reference operator*() const {
                return *ptr;
            }
            const pointer operator->() const {
                return ptr;
            }

            const_reference operator [](size_type index) {
                return ptr[index];
            }

            // const const const_interator& operator+=(size_type ) {

            // }
            const_interator operator+(const size_type x) const {
                return new const_interator{ ptr+ x};
            }
            difference_type operator-(const const_interator& rhv) const {
                return ptr - rhv.ptr;
            }

            bool operator<=>(const const_interator& rhv) const = default;
        protected:
            explicit const_interator(pointer p) : ptr(p) {}
        private:
            pointer ptr {nullptr};
    };
    

    class iterator: public const_interator {
        private:
            friend Vector<T> vec;
        public:
            iterator() : const_interator {

            }
    };

};


int main () {

}