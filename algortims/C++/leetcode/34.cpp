// 34. Find First and Last Position of Element in Sorted Array
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        std::vector<int> candidates;
        while (start != end)
        {
            int middle = start + (end - start) / 2;
            if (nums[middle] == target)
            {
                candidates.push_back(middle);
                end = middle - 1;
            }
            else if (nums[middle] < target)
            {
                start = middle + 1;
            }
            else if (nums[middle] > target)
            {
                end = middle - 1;
            }
        }
        for (auto x : candidates)
        {
            std::cout << x << std::endl;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{5, 7, 7, 8, 8, 10};
    auto res = sol.searchRange(vec, 8);
    for (auto x : res)
    {
        std::cout << x << std::endl;
    }
}