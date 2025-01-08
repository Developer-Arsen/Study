#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t N>
size_t upper_bound(T (&arr)[N], T target) {
    int start = 0 ;
    int end = N - 1;
    while (start <= end) {
        int mid = start + ((end  - start) / 2);

        if (arr[mid] <= target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        } 
    }
   
    return start;
}

int main () {
    int arr[] = {10,20,25,25,25,25, 30,40};
    std::cout << upper_bound(arr, 25) << std::endl;
}