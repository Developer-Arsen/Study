#include <iostream>
#include <type_traits>

template<typename T>
class Vector {
    T* data;
    size_t size;
    size_t capacity;

    public:
        Vector() : size(0) , capacity(10) , data(new T[10]) {}

        Vector(T& val) : Vector() {
            data[size] = val;
        }

        Vector(std::initializer_list<T> list) : Vector() {
            for (const auto &x : list) {
                push_back(x);
            }
        }

        void push_back(const T& val) {
            if (size == capacity) {
                capacity *= 2;

                T* tmp = data;
                data = new T[capacity];
                for (size_t i  = 0 ; i < size; ++i) {
                    data[i] = tmp[i];
                }
                delete [] tmp;
            }

            data[size++] = val;
        }

        template<typename U>
        friend std::ostream& operator <<(std::ostream& os, const Vector<U>& vec) {
            os << "start";

            for (size_t i = 0 ; i < vec.size; ++i) { 
                os << vec.data[i] << ",";
            }
            os << "end" ;

            return os;
        }
    
        class Iterator {
            private:
                T* vec_pointer;
            public:
                using iterator_category = std::random_access_iterator_tag;
                using value_type = T;
                using reference = value_type&;
                using pointer = value_type*;
                using difference_type = std::ptrdiff_t;
                using size_type = size_t;

                Iterator(T* ptr) : vec_pointer(ptr) {}

                reference operator*() {
                    return *vec_pointer;
                }

                Iterator& operator++() {
                    vec_pointer++;
                    return *this;
                }

                Iterator operator++(int) {
                    Iterator tmp = *this;
                    ++(*this);
                    return tmp;
                }
                
                bool operator !=(const Iterator& other) {
                    return vec_pointer != other.vec_pointer;
                }

                reference operator [](size_type index ) const {
                    return data[index];
                }
        };

        Iterator begin() {
            return Iterator(data);
        }
        
        Iterator end() {
            return Iterator(data+size);
        }

};

int main () {

    Vector<int> vec{1,2,4};

    for (const auto& item : vec) {
        vec.push_back(10);
        std::cout << item << std::endl;
    }

    std::cout << vec[1] << std::endl;



}