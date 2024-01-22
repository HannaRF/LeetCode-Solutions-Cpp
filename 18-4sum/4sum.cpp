#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> solutions = {};

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates for the first element
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;  // Skip duplicates for the second element
                }

                long long remainingTarget = target - static_cast<long long>(nums[i]) - static_cast<long long>(nums[j]);
                int left = j + 1; // left pointer
                int right = n - 1; // right pointer

                while (left < right) {
                    if (left > j + 1 && nums[left] == nums[left - 1]) {
                        left++;
                        continue;  // Skip duplicates for the third element
                    }

                    if (right < n - 1 && nums[right] == nums[right + 1]) {
                        right--;
                        continue;  // Skip duplicates for the fourth element
                    }

                    // int currentSum = nums[i] + nums[j] + nums[left] + nums[right];
                    long long currentSum = static_cast<long long>(nums[i]) +
                                           static_cast<long long>(nums[j]) +
                                           static_cast<long long>(nums[left]) +
                                           static_cast<long long>(nums[right]);

                    if (currentSum == target) {
                        solutions.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    } else if (currentSum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return solutions;
    }
};
