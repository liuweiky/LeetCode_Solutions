class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int* dp = new int[triangle.size()];
        int* prev = new int[triangle.size()];
        
        for (int i = 0; i < triangle.back().size(); i++)
        {
            prev[i] = triangle.back()[i];
            dp[i] = triangle.back()[i];
        }
        
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
                dp[j] = min(prev[j], prev[j + 1]) + triangle[i][j];
            memcpy(prev, dp, triangle.size() * sizeof(int));
        }
        
        return prev[0];
    }
};
