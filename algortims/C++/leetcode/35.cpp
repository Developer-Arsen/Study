// 35. Search Insert Position
//                     Given a sorted array of distinct integers and a target value,
//     return the index if the target is found.If not, return the index where it would be if it were inserted in order.

//                                                            You must write an algorithm with
//                                                            O(log n) runtime complexity.

//                                                            Example 1 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 5 Output : 2 Example 2 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 2 Output : 1 Example 3 :

//     Input : nums = [ 1, 3, 5, 6 ],
//             target = 7 Output : 4

#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        std::vector<int> candidates;
        int middle = 0;

        while (start != end)
        {
            middle = start + (end - start) / 2;

            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] < target)
            {
                std::cout << "here" << middle << std::endl;
                start = middle + 1;
            }
            else if (nums[middle] > target)
            {
                std::cout << "here -1" << std::endl;
                end = middle - 1;
            }
        }
        return middle;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 3, 5, 6};
    // 0 + 3 = 1
    // 1 + 3 = 2
    // 2 + 3 = 3
    auto res = sol.searchInsert(vec, 7);
    std::cout << res << std::endl;
}