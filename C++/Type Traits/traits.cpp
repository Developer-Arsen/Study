#include <iostream>


template<typename T>
struct is_const
{
    enum { value = false };
};

template<typename T>
struct is_const<const T> {
    enum { value = true };
};

template<typename T>
constexpr bool is_const_v = is_const<T>::value;


template<typename T>
struct is_void {
    enum { value = false};
};

template<>
struct is_void<void> {
    enum { value = true};
    
}; 

struct true_type
{
    enum { value = true};
    using type = true_type;
};

struct false_type
{
    enum { value = false};
    using type = false_type;
};

template<typename T, typename U>
struct is_same : false_type {};

template<typename T>
struct is_same<T, T> : true_type {};

template<typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;




int main () {
  std::cout << "is_same<int, int>::value: " << is_same<int, int>::value << "\n";     // Outputs 1 (true)
    std::cout << "is_same<int, float>::value: " << is_same<int, float>::value << "\n"; // Outputs 0 (false)
    std::cout << "is_same<float, float>::value: " << is_same<float, float>::value << "\n"; // Outputs 1 (true)
}
