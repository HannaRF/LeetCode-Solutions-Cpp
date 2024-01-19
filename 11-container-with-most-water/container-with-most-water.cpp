#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            maxArea = std::max(maxArea, h * w);

            if (height[left] < height[right]) ++left;
            else --right; 
        }
        return maxArea;
    }
};
