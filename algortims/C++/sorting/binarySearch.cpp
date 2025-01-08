#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, size_t N>
bool binarySearch(T (&arr)[N], T target) {
    int start = 0 ;
    int end = N - 1;
    while (start <= end) {
        int mid = start + ((end  - start) / 2);

        if (arr[mid] > target) {
            end = mid - 1;
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            return true;
        }
    }
   
    return false;
}

template<typename T, size_t N>
bool binarSearchRecursive(T(&arr)[N], T targert, int start = 0, int end = N) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] > targert) {
        return binarSearchRecursive(arr, targert, start, mid - 1);
    }
    if (arr[mid] < targert) {
        return binarSearchRecursive(arr, targert, mid + 1, end);
    }
    return true;
}

int main () {
    int arr[] = {1,2,3,4,5};
    std::cout << binarySearch(arr, 1) << std::endl;
    std::cout << binarSearchRecursive(arr, 2) << std::endl;
}