#include <vector>
#include <iostream>

void maxProfit(std::vector<int>& arr) {
    int max = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int profit = 0;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] - arr[i] > profit) {
                profit = arr[j] - arr[i];
            }
        }
        if (profit > max) {
            max = profit;
        }
    }
    std::cout << max << std::endl;
}

void findMaximumSubArray(std::vector<int>& arr, int low, int high) {
    if (start >= end) {
        return;
    }
    else {
        int mid = low + (high - low) / 2;
        

    }
}


void maxProfitWithN(std::vector<int>& arr) {
    int max = 0;
    int min = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        min = min > arr[i] ? arr[i] : min;
        int profit = arr[i] - min;
        max = max < profit ? profit : max;
    }
    std::cout << max << std::endl;

}

int main() {
    std::vector<int> numbers = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
    maxProfitWithN(numbers);
    return 0;
}
