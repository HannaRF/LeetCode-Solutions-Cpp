#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solutions = {};

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates for the first element
            }

            int target = -nums[i];
            int j = i + 1; // left
            int k = n - 1; // right

            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;  // Skip duplicates for the second element
                }

                if (k < n - 1 && nums[k] == nums[k + 1]) {
                    k--;
                    continue;  // Skip duplicates for the third element
                }

                if (target == nums[j] + nums[k]) {
                    solutions.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (target < nums[j] + nums[k]) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return solutions;
    }
};
