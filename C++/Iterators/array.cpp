#include <iostream>
#include <iterator>
#include <algorithm>
#include <type_traits>


template<typename T, size_t N>
class Array {
    T arr[N];
    public:
        Array(std::initializer_list<T> list) {
            for (size_t i = 0 ; i < list.size(); ++i) {
                arr[i] = *(list.begin() + i);
            }
        }

        class const_iterator {
            friend Array<T, N>;

            public:
                using value_type = T;
                using reference = value_type&;
                using pointer = value_type*;
                using difference_type = std::ptrdiff_t;
                using iterator_category = std::random_access_iterator_tag;
                using const_reference = const reference;
            
                const_iterator() = default;

                const const_iterator& operator++(){
                    ++ptr;
                    return *this;
                } 

                const const_iterator& operator++(int) {
                    const_iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }

                const const_iterator& operator--(){
                    ptr--;
                    return *this;
                } 

                const const_iterator& operator--(int){
                    const_iterator tmp = *this;
                    --(*this);
                    return tmp;
                }

                bool operator <=>(const const_iterator& other) const = default;

                std::conditional_t<std::is_fundamental_v<value_type>, value_type, const_reference> 
                operator [](size_t index) {
                    return ptr[index];
                }

                std::conditional_t<std::is_fundamental_v<value_type>, value_type, const_reference>
                operator *() const {
                    return *ptr;
                }

                const pointer operator ->() {
                    return ptr;
                }

                const_reference operator +=(size_t size) {
                    ptr += size;
                    return *this;
                } 

                const_reference operator -=(size_t size) {
                    ptr -= size;
                    return *this;
                } 

                const_reference operator +(size_t size) const {
                    return const_iterator(ptr + size);
                } 
                
                const_reference operator -(size_t size) const {
                    return const_iterator(ptr - size);
                } 

                difference_type operator -(const const_iterator& other) const {
                    return ptr - other.ptr;
                } 

            protected:
                explicit const_iterator(pointer p) : ptr{p} {};
            private:
                pointer ptr;

        };

        class iterator : public const_iterator {
            friend Array<T,N>;

            protected:
                explicit iterator(const_iterator::pointer p) : const_iterator{p} {}
            public:
                using value_type = T;
                using reference = value_type&;
                using pointer = value_type*;
                using difference_type = std::ptrdiff_t;
                using iterator_category = std::random_access_iterator_tag;
                using const_reference = const reference;

                std::conditional_t<std::is_fundamental_v<typename const_iterator::value_type>, typename const_iterator::value_type, typename const_iterator::const_reference>
                operator [](size_t index) const {
                    return this->const_iterator::operator[](index);
                } 

                reference operator [](size_t index) {
                    return this->ptr[index];
                }

                const pointer operator -> () const {
                    return this->const_iterator::operator->();
                }

                pointer operator-> () {
                    return const_cast<pointer>(static_cast<const iterator*>(this)->operator->());
                }

                std::conditional_t<std::is_fundamental_v<value_type>, value_type, const_reference>
                operator*() const {
                    return this->const_iterator::operator*();
                }

                reference operator*() {
                    return *(this->ptr);
                }
        };

    iterator begin ()  {
        return iterator{arr};
    }

    iterator end ()  {
        return iterator{arr + N};
    }

    const_iterator begin () const {
        return const_iterator{const_cast<Array<T, N>&>(*this).arr};
    }

    const_iterator end () const {
        return const_iterator{const_cast<Array<T, N>&>(*this).arr + N};
    }

   


    template<typename U, size_t M>
        friend std::ostream& operator <<(std::ostream& os, const Array<U, M>& other) {
            os << "start" << std::endl;

            for (auto it = other.begin() ; it != other.end(); ++it) {
                os << *it << ",";
            }

        return os;
    }


};

int main () {

    Array<int, 3>  arr{1,2,3};
    std::cout << arr << std::endl;

    std::cout << *std::find_if(arr.begin(), arr.end(), [](const int x){
        return (x % 3 == 0);
    }) << std::endl;;

    
}