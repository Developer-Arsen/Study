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
    enum { value = true };
    // using type = true_type;
};

struct false_type
{
    enum { value = false};
    // using type = false_type;
};

template<typename T, typename U>
struct is_same : false_type {};

template<typename T>
struct is_same<T, T> : true_type {};

template<typename T, typename U>
constexpr bool is_same_v = is_same<T, U>::value;

template<typename T>
struct add_const {
    
};


template<typename T>
struct is_default_constructable{
    private:
        template<typename U>
        static auto test(void *) -> decltype(U(), true_type {}) {}

        template<typename>
        static false_type test(...) {}

    public:
        enum { value = decltype(test<T>(nullptr))::value };
};

struct Arsen {
    Arsen() = delete;
};

template<typename T, typename U>
struct is_convertible {
    private:
        static void helper(T);

        template<typename F, typename S>
        static auto test(void *) -> decltype(helper(std::declval<S>()), true_type {});

        template<typename F, typename S>
        static false_type test(...);

    public:
        enum { value = decltype(test<T, U>(nullptr))::value };
};


template<typename T, typename U>
struct is_base_of {
    private:
        template<typename B, typename D>
        static auto test(void*) -> std::enable_if_t< 
            std::is_class<B>::value && 
            std::is_class<D>::value &&
            !std::is_same<B,D>::value &&
            std::is_convertible<D*, B*>::value,
            true_type
        >;
        
        template<typename , typename >
        static false_type test(...);

    public:
        enum { value = decltype(test<T, U>(nullptr))::value };
};

template<typename T>
struct is_plus {
    private:
        template<typename U>
        static void aux(U) {}

        template<typename B>
        static auto test(void*) -> decltype(aux(std::declval<B>() + std::declval<B>()), true_type {});
        
        template<typename>
        static false_type test(...);

    public:
        enum { value = decltype(test<T>(nullptr))::value };
};


struct A {
    void operator+(const A& other) {
        // return *this;
    }
};
struct B : A {};

struct C {};

int main () {
//   std::cout << "is_same<int, int>::value: " << is_same<int, int>::value << "\n";     // Outputs 1 (true)
//     std::cout << "is_same<int, float>::value: " << is_same<int, float>::value << "\n"; // Outputs 0 (false)
//     std::cout << "is_same<float, float>::value: " << is_same<float, float>::value << "\n"; // Outputs 1 (true)

    
    // std::cout << is_default_constructable<Arsen>::value <<std::endl;
    // std::cout << is_base_of<int, int>::value <<std::endl;
    std::cout << is_base_of<A, C>::value <<std::endl;
    // std::cout << is_plus<A>::value <<std::endl;
    // std::cout << is_convertible<int, A>::value <<std::endl;
}
