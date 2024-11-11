#include <iostream>
#include "list.hpp"

int main () {

    List list {1,2,3,4};
    list.push_front(5);
    list.push_back(10);

    // List ls2 {list};
    // List ls3 {std::move(list)};

    std::cout << list << std::endl;   
}