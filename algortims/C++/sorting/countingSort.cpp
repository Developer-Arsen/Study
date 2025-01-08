#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
T& countingSort(T &arr) {
    if (arr.empty()) return arr;

    int maxV = *std::max_element(arr.begin(), arr.end());
    int minV = *std::min_element(arr.begin(), arr.end());
    int range = maxV - minV + 1;

    std::vector<int> countedArr(range, 0);

    for (int item : arr) {
        countedArr[item - minV]++;
    }

    int index  = 0;
    for (int i = 0; i < range; ++i) {
        while (countedArr[i]--) {
            arr[index++] = i + minV;
        }
    }

    return arr;
}

template<typename T> 
void countingSortStable(T& arr) {
    if (arr.empty()) return;
    int maxV = *std::max_element(arr.begin(), arr.end());
    int minV = *std::min_element(arr.begin(), arr.end());
    int range = maxV - minV + 1;

    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    for (auto item: arr) {
        count[item - minV]++;
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; --i) {
        int num = arr[i];
        output[count[num -minV] - 1] = num;
        count[num-minV]--;
    }

    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = output[i];
    }
}



int main () {
    std::vector<int> arr {2,1,1,1,2,3,4,5};
    countingSortStable(arr);
    for(auto x : arr) {
        std::cout << x << std::endl;
    }
}