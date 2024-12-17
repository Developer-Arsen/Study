#include <iostream>


// int test() { 
//     return 0; 
// }
// template<typename T, typename... Args>
// int test(T first, Args... arg) {
//     std::cout<< first << std::endl;
//     return 1 + test(arg...); 
// }

// template<typename T, template... Args>
// struct count_args {
//     enum {value = count_args<T, Args...>::value};
// };

// template<typename T>
// struct count_args<T> {
//     enum { value = 1 };
// };

template<typename... Args>
int print(Args... args) {
   int sum =  (10 +  ... +  args);
    std::cout << std::endl;
    return sum;
}



int main() {
    // std::cout << count_args(1, 2, 3) << std::endl; 
    std::cout << print(1,2,3) << std::endl; 

    return 0;
}
