#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace chrono;

// Merge function for merge sort
void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> tmp(end - start + 1);
    int index = 0, st1 = start, end1 = mid, st2 = mid + 1;

    while (st1 <= end1 && st2 <= end) {
        if (arr[st1] < arr[st2]) {
            tmp[index++] = arr[st1++];
        } else {
            tmp[index++] = arr[st2++];
        }
    }

    while (st1 <= end1) {
        tmp[index++] = arr[st1++];
    }

    while (st2 <= end) {
        tmp[index++] = arr[st2++];
    }

    for (int i = 0; i < tmp.size(); ++i) {
        arr[start + i] = tmp[i];
    }
}

// Merge sort implementation
void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

// Insertion sort implementation
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int& num : arr) {
        num = rand() % 10000; // Random numbers between 0 and 9999
    }
    return arr;
}

int main() {
    const int iterations = 10000; // Number of times to sort the array
    int startSize = 10;           // Starting size of the array
    int endSize = 500;            // Maximum size to test
    int step = 10;                // Step size for increasing array size

    cout << "Size, MergeSortTime(ms), InsertionSortTime(ms)" << endl;

    for (int size = startSize; size <= endSize; size += step) {
        long long mergeSortTime = 0, insertionSortTime = 0;

        for (int iter = 0; iter < iterations; ++iter) {
            vector<int> arr1 = generateRandomArray(size);
            vector<int> arr2 = arr1; // Copy for fair comparison

            // Measure merge sort time
            auto start = high_resolution_clock::now();
            mergeSort(arr1, 0, arr1.size() - 1);
            auto end = high_resolution_clock::now();
            mergeSortTime += duration_cast<microseconds>(end - start).count();

            // Measure insertion sort time
            start = high_resolution_clock::now();
            insertionSort(arr2);
            end = high_resolution_clock::now();
            insertionSortTime += duration_cast<microseconds>(end - start).count();
        }

        cout << size << ", " << mergeSortTime / 1000.0 << ", " << insertionSortTime / 1000.0 << endl;
    }

    return 0;
}
