#include <iostream>
#include <vector>

template<typename T, size_t N>
T(&merge(T (&arr)[N], int start, int mid, int end))[N] {
    T tmp[end - start + 1];
    int index = start;
    int st1 = start;
    int end1 = mid;

    int st2 = mid + 1;
    
    while (st1 <= end1 && st2 <= end) {
        if (arr[st1] < arr[st2]) {
            tmp[index++] = arr[st1++];
        } else {
            tmp[index++] = arr[st2++];
        }
    }

    while (st1 <= end1)
    {
        tmp[index++] = arr[st1++];
    }

    while (st2 <= end)
    {
        tmp[index++] = arr[st2++];
    }

    for (auto x : tmp) {
        arr[start++] = x;
    }
    
    
    return arr;
} 


template<typename T, size_t N>
T(&mergeSort(T (&arr)[N], int start = 0, int end = N - 1))[N] {
    if (start >= end) {
        return arr;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);

    return arr;
}


int main () {
    int vec[] = {2,6,7,2,3};
    mergeSort(vec);
    for(auto x : vec) {
        std::cout << x << std::endl;
    }
}