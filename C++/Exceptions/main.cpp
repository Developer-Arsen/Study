#include <iostream>
#include <stdexcept>

void foo () {
    throw 4;
}

void too () {
    try {
        foo();
    } catch (int x) {
        std::cout << "gotexeception" << std::endl;
        throw;
    }
}

int main () {
    try {
        too();
    } catch (int x) {
        std::cout << "mineeeeeeeeee" << std::endl;
    } 
    
}