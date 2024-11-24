#include <iostream>
#include <vector>

template<typename Container, typename Func, typename T=std::size_t>
T accumulate(Container& container, T init, Func func) {
    for (size_t i = 0; i < container.size(); ++i) {
        init = func(init, container.at(i));
    }
    return init;
}

template<typename FilterContainer, typename Func>
void addFilter(FilterContainer &filters, Func&& func) {
    filters.emplace_back(func);
}

template<typename Elem, typename Predicates>
bool all_of(Elem element, Predicates& filters) {
    for (auto filter : filters) {
        if (!filter(element)) {
            return false;
        }
    }

    return true;
}


int main() {
    std::array arr {1,2,3, 15, 9};

    std::vector<std::function<bool(size_t)>> filters;
    addFilter(filters, [](size_t x) { if (x % 3 == 0) return true; else return false; });
    addFilter(filters, [](size_t x) { if (x % 5 != 0) return true; else return false; });

    // for (size_t i = 0 ; i < arr.size(); ++i) {
    //     if (all_of(arr.at(i), filters)) {
    //         std::cout <<  arr.at(i) << ": this is elem : true case" << std::endl;
    //     } else {
    //         std::cout <<  arr.at(i) << ": this is elem : false case" << std::endl;
    //     }
    // }

    auto f = [](int x, auto f) {
        if(x > 1) return f(x-1, f) + f(x-2, f);

        if (x == 0) return 0;
        if (x == 1) return 1;
        
    };
    
    // std::function<int(int)> f = [&f](int x) {
    //     if (x == 0) return 0;
    //     if (x == 1) return 1;
    //     return f(x-1) + f(x-2);
        
    // };

    std::cout << f(12, f) << std::endl;



}