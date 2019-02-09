class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = INT_MIN;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int min_height = min(height[i], height[j]);
            max_area = max(max_area, min_height * (j - i));
            while (i < j && height[i] <= min_height)
                i++;
            while (i < j && height[j] <= min_height)
                j--;
        }
        return max_area;
    }
};
