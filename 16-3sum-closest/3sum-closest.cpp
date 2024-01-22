class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int diff = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates for the first element
            }

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

                int currentSum = nums[i] + nums[j] + nums[k];
                int currentDiff = target - currentSum;

                if (std::abs(currentDiff) < std::abs(diff)) {
                    diff = currentDiff;
                }

                if (currentSum == target) {
                    return target;
                } else if (currentSum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return target - diff;
    }
};
