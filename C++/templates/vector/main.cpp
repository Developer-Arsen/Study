#include <iostream>
#include "vector.hpp"

int main() {
    // Test default constructor and push_back
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    std::cout << "Vector elements after push_back: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Test initializer list constructor
    Vector<int> vec2 = {1, 2, 3, 4, 5};
    std::cout << "Vector created with initializer list: ";
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Vector<int> vec3 = vec2;
    std::cout << "Vector created with copy constructor: ";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    // Test move constructor
    Vector<int> vec4 = std::move(vec3);
    std::cout << "Vector created with move constructor (vec3 moved to vec4): ";
    for (int i = 0; i < vec4.size(); ++i) {
        std::cout << vec4[i] << " ";
    }
    std::cout << std::endl;

    // Test pop
    vec2.pop();
    std::cout << "Vector after pop: ";
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // Test is_empty
    std::cout << "Is vec2 empty? " << (vec2.is_empty() ? "Yes" : "No") << std::endl;

    // Test at()
    int index = vec2.at(3);
    if (index != -1) {
        std::cout << "Found 3 at index: " << index << std::endl;
    } else {
        std::cout << "3 not found in the vector" << std::endl;
    }

    return 0;
}
