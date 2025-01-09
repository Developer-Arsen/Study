#include <iostream>

template<typename T, size_t N> 
int partitionWithFirst(T (&arr)[N], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) 
    {
        if (arr[i] < pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    std::swap(arr[j], arr[low]);
    return j;
} 

template<typename T, size_t N> 
int partitionWithLast(T (&arr)[N], int low, int high) {
    int pivot = arr[high];
    int i = low;
    int j = high - 1;
    while (i <= j) 
    {
        if (arr[i] < pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    std::swap(arr[i], arr[high]);
    return i;
} 

template<typename T, size_t N> 
int partitionWithLastOtherWay(T (&arr)[N], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = 0; j < high; ++j) {
        if (arr[j] <= pivot) {
            std::swap(arr[j], arr[i]);
            i++;
        }
    }
    std::swap(arr[i], arr[high]);
    std::cout << i << std::endl;
    return i;
}


template<typename T, size_t N>
T(&quickSort(T (&arr)[N], int low = 0, int high = N - 1))[N] {
    if (low >= high) return arr;

    int pivot = partitionWithLastOtherWay(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);

    return arr;
}


int main () {
    int arr[] = {5,2,4,6,5};
    quickSort(arr);

    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }    
    std::cout << std::endl;
}