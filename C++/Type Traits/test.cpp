#include <type_traits>
#include <vector>

template<typename T>
struct is_void : std:false_type {};

template<>
struct is_void<void> : std::true_type{};


template<typename T>
struct remove_cv : std::type_identity<T> {};

template<typename T>
struct remove_cv<T const> : std::type_identity<T>{};

template<typename T>
struct remove_cv<T volatile> : std::type_identity<T>{};

template<typename T>
struct remove_cv<T volatile const> : std::type_identity<T>{};


template<typename T>
struct remove_extent {
    using type = T;
};

template<typename T>
struct remove_extent<T[]> {
    using type = T;
};

template<typename T, size_t N>
struct remove_extent<T[N]> {
    using type = T;
};

