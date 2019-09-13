class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0)
            return 0;
        
        int prev_min = prices[0];
        
        int ans = INT_MIN;
        
        for (int i = 1; i < prices.size(); i++)
        {
            ans = max(prices[i] - prev_min, ans);
            prev_min = min(prev_min, prices[i]);
        }
        
        return ans > 0 ? ans : 0;
    }
};
