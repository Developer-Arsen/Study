#include <type_traits>
#include <vector>
#include <iostream>
#include <typeinfo> // For typeid

template<typename T>
struct is_void : std::false_type {};

template<>
struct is_void<void> : std::true_type {};



template<typename T, typename U>
struct is_same : std::false_type {};

template<typename T>
struct is_same<T, T> : std::true_type {};


// template <typename T>
// struct is_polymorphic {
//     private:
//         template<typename U>
//         static std::true_type test(decltype(dynamic_cast<void*>((U*) nullptr)));

//         template<typename U>
//         static std::false_type test(...);
//     public:
//         enum { value = decltype(test<T>(nullptr))::value} 
// };


// template<typename T>
// concept Poly = requires(T * ptr) {
//     { dynamic_cast<void*>(ptr)} -> std::same_as<void*>;
// };

// template<typename T>
// struct is_polymorphic
// {
//     static constexpr bool value = Poly<T>;
// };


// template<typename T>
// struct is_polymorphic {
//     private:
//         template<typename U>
//         static std::true_type test(decltype(dynamic_cast<void*>((U*) nullptr)));

//         template<typename U>
//         static std::false_type test(...);
//     public:
//         enum { value = decltype(test<T>(nullptr)):: value};
// };

template<typename T>
concept Poly = requires(T* ptr) { 
    { dynamic_cast<void*>(ptr) } -> std::same_as<void*>;
};

template<typename T>
concept hasPlus = requires(T obj) {
    { obj + obj} -> std::same_as<T>;
};

template<typename T>
struct is_polymorphic {
    static constexpr bool value = Poly<T>;
};

template<typename T>
struct has_plus {
    static constexpr bool value = hasPlus<T>;
};

struct Base { virtual ~Base() = default; }; // Polymorphic
struct Derived : Base {}; // Polymorphic
struct NonPolymorphic {}; // Not polymorphic

struct Addable {
    int value;
    Addable operator+(const Addable& other) const {
        return Addable{value + other.value};
    }
};

struct NonAddable {};

template<hasPlus T>
void check_has_plus(const T& obj) {
    std::cout << typeid(obj).name() << " This type supports the + operator.\n";
}

int main() {
    std::cout << "Addable has plus: " << has_plus<Addable>::value << "\n"; // Outputs 1 (true)
    std::cout << "NonAddable has plus: " << has_plus<NonAddable>::value << "\n"; // Outputs 0 (false)

    Addable a1, a2;
    if constexpr (has_plus<Addable>::value) {
        check_has_plus(a1); // Valid
    }
}
