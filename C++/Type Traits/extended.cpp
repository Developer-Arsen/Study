#include "graph.hpp"
#include "util.hpp"
#include <type_traits>
#include <vector>

namespace atlas {
    template <typename T>
    struct is_void : std::false_type {};

    template <>
    struct is_void<void> : std::true_type {};

    template <typename T>
    struct remove_cv : std::type_identity<T> {};

    template <typename T>
    struct remove_cv<T const> : std::type_identity<T> {};

    template <typename T>
    struct remove_cv<T volatile> : std::type_identity<T> {};

    template <typename T>
    struct remove_cv<T volatile const> : std::type_identity<T> {};

    template <typename T, size_t N = 0>
    struct extent : std::integral_constant<T, N> { }; 

    template <typename T>
    struct remove_extent {
        using type = T;
    };

    template <typename T>
    struct remove_extent<T[]> {
        using type = T;
    };

    template <typename T, size_t N>
    struct remove_extent<T[N]> {
        using type = T;
    };

    template <typename T>
    struct has_less_than {
    private:
        template <typename U>
        static auto test(void *) -> decltype(std::declval<U>() < std::declval<U>(), std::true_type {});

        template <typename U>
        static std::false_type test(...);

    public:
        enum { value = decltype(test<T>(nullptr))::value };
    };

    template <typename ...>
    using void_t = void;

    template <typename, typename = std::void_t<>>
    struct has_less : std::false_type { };

    template <typename T>
    struct has_less<T, std::void_t<decltype(std::declval<T>() < std::declval<T>())>> : std::true_type {};

    template <typename T>
    struct decay {
    private:
        using U = std::remove_reference_t<T>;
    public:
        using type = std::conditional_t<std::is_array_v<U>, 
            std::add_pointer_t<typename atlas::remove_extent<U>::type>,
                std::conditional_t<std::is_function_v<U>,
                std::add_pointer_t<U>,
                std::remove_cv<std::remove_reference_t<U>>>>;
    };


    template <typename T>
    struct is_polymorphic {
    private:
        template <typename U>
        static std::true_type test(decltype(dynamic_cast<void *>((U *)nullptr)));

        template <typename U>
        static std::false_type test(...);

    public:
        enum { value = decltype(test<T>(nullptr))::value };
    };

    namespace detail {
        
        template <size_t N, size_t Div = N / 2>
        struct _is_prime {
            enum { value = N % Div != 0 && _is_prime<N, Div - 1>::value };
        };

        template <size_t N>
        struct _is_prime<N, 1> {
            enum { value = true };
        };

        template <size_t N, bool pred>
        struct _next_prime_helper {
            enum { value = _next_prime_helper<N + 1, _is_prime<N + 1>::value>::value };
        };

        template <size_t N>
        struct _next_prime_helper<N, true> {
            enum { value = N };
        };

        template <size_t N>
        struct _next_prime {
            enum { value = _next_prime_helper<N + 1, _is_prime<N + 1>::value>::value };
        };

        template <size_t N, size_t M>
        struct output_kth_prime {
            enum { value = output_kth_prime<_next_prime<N + 1>::value, M - 1>::value };
        };

        template <size_t N>
        struct output_kth_prime<N, 0> {
            enum { value = N };
        };
    }

    template <size_t N>
    using is_prime = detail::_is_prime<N>;

    template <size_t N>
    using next_prime = detail::_next_prime<N>;

    template <size_t N, size_t M = 2>
    struct kth_prime {
        static_assert(detail::_is_prime<M>::value);

        enum { next_prime = detail::_next_prime<N>::value };
        enum { value = detail::output_kth_prime<next_prime, M>::value };
    };
}

template <typename T>
class Base {
public:
    Base() {
    }
    
    void interface() {
        static_cast<T *>(this)->implementation(); 
    }
};

class Derived : public Base<Derived> {
public:
    Derived() {
    }

    void implementation() {
        std::cout << "derived\n";
    }

    ~Derived() { std::cout << "derived\n"; };
};

class Derived1 : public Base<Derived1> {
public:
    Derived1() {
    }

    void implementation() {
        std::cout << "derived1\n";
    }

    ~Derived1() { std::cout << "derived1\n"; }
};

template <typename T>
void foo(Base<T> *ptr)
{
}

int main()
{
    Base<Derived> *obj = new Derived;
    Base<Derived1> *obj1 = new Derived1;

    delete obj;
    delete obj1;

    auto x = atlas::kth_prime<30>::value;
    atlas::kth_prime<90>::value;
    atlas::kth_prime<100>::value;
    atlas::kth_prime<102>::value;
}