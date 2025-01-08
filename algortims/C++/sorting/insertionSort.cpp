
#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t N>
T(&insertionSort(T(&arr)[N], bool ASC = true))[N]{
    for (int i = 1; i < N; ++i) {
        int j = i - 1;
        int val = arr[i];
        
        while (j >= 0 && arr[j] > val) {
            arr[j+1] = arr[j];
            j--;
        }
        if (i != j) {
            arr[j + 1] = val;
        }
    }

    return arr;
}

int main () {
    double arr[] = {0,0,0,2,2,2,100,2,7,5,1,1,7,5,4};
    insertionSort(arr, false);

    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }    
    std::cout << std::endl;
}