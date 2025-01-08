#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t N>
T(&bubleSort(T (&arr)[N], bool ASC = true))[N]{
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (ASC) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            } else {
                if (arr[j] < arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }  
            }
        }
    }
    return arr;
}

int main () {
    double arr[] = {2.1,1,7,5,4};
    bubleSort(arr, false);

    for (const auto& elem : arr) {
        std::cout << elem << "";
    }    
    std::cout << std::endl;
}