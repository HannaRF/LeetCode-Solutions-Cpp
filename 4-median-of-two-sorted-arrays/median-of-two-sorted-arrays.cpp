class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> nums = {};
        int i = 0;
        int j = 0;

        while (i < m || j < n) {
            if (j == n || (i < m && nums1[i] <= nums2[j])) {
                nums.push_back(nums1[i]);
                ++i;
            } else {
                nums.push_back(nums2[j]);
                ++j;
            }
        }

        int l = nums.size();
        if (l % 2 == 0) {
            return (nums[l / 2 - 1] + nums[l / 2]) / 2.0;  // double division
        } else {
            return nums[l / 2];
        }
    }
};