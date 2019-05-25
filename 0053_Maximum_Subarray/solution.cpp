class Solution {
public:
    
    int* dp;
    int ans;
    
    int maxSubArray(vector<int>& nums) {
        dp = new int[nums.size()];
        ans = dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
