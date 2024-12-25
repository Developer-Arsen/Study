#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t N>
T(&selectionSort(T (&arr)[N], bool ASC = true))[N] {
    int index = 0;
    for (int i = 0 ; i < N; ++i) {
        index = i;
        for (int j = i + 1; j < N; ++j) {
            if (ASC) {
                if (arr[index] > arr[j]) {
                    index = j;
                }
            } else {
                if (arr[index] < arr[j]) {
                    index = j;
                }
            }
        }
        if (index != i) {
            swap(arr[index], arr[i]);
        }
    }
    return arr;
}

int main () {
    int arr[] = {5,2,4,6,5};
    selectionSort(arr, false);

    for (const auto& elem : arr) {
        std::cout << elem << "";
    }    
    std::cout << std::endl;
}