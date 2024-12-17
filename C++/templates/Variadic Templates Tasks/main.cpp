#include <iostream>
#include <type_traits>


// template<typename T, typename... Args>
// struct is_unique {
//     enum { value = (std::is_same_v<T, Args> || ...)};
// };

// template<typename T, typename... Args>
// struct count_types {
//     enum { value = !is_unique<T, Args...>::value + count_types<Args...>::value };
// };

// template<typename T>
// struct count_types<T>
// {
//     enum {value = 1};
// };


// template<typename T, typename... Args>
// std::common_type_t<T, Args...> max_value(T val, Args... args) {
//     if constexpr (sizeof...(Args)) {
//         auto sum = max_value<std::common_type_t<T, Args...>>(args...);
//         return sum < val ? val : sum;
//     } else {
//         return val;
//     }
// }


// template<typename T, typename... Args>
// std::common_type_t<T, Args...> max_value(T val, Args... args) {
//     if constexpr (sizeof...(Args)) {
//         auto sum = max_value(args...);
//         return sum < val ? val : sum; 
//     } 
//     return val;
// }   

template<typename T>
class WDec{
    private:
        T const& wrapee;
    
    public:
    WDec(const T& obj) : wrapee(obj) {} 

    friend std::ostream& operator<<(std::ostream& os, const WDec& w) {
        return os << "," << w.wrapee;
    }
};

template<typename... Args>
void print(Args const& ... args) {
    (std::cout << ... << WDec(args)) << std::endl;
}


template<typename T, typename... Args>
void printReverse(T val, Args... args) {
    if constexpr (sizeof...(Args)) {
        printReverse(args...);
        std::cout << val << std::endl; 
    } else {
        std::cout << val << std::endl; 
    }
}

#include <sstream>   // Include this for std::ostringstream

template <typename T>
std::string replace_first_placeholder(const std::string& fmt, T arg) {
    size_t pos = fmt.find("{}");
    std::ostringstream oss;
    oss << arg;
    return fmt.substr(0, pos) + oss.str() + fmt.substr(pos + 2);
}

template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    if constexpr (sizeof...(Args)) {
        return replace_first_placeholder(fmt, args...);
    } else {
        return fmt;
    }
    
}

int main () {
    // std::string hello {"h"};
    // std::string alo {"l"};
    // print();
    // printReverse(1,2,3);
    std::cout << format("Hello {}!", "World") << std::endl;
    std::cout << format("Hello, {}!", "World") << std::endl;
    // std::cout << max_value(1,9.8,3,5) << std::endl;
    //  max_value(1,2,3,5);
    // std::cout << "Number of types: " << count_types<int, int,  double, char>::value << std::endl;
}