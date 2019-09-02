class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stk;
        
        for (int i = 0; i <= heights.size(); i++)
        {
            int h = (i == heights.size() ? 0 : heights[i]);
            if (stk.size() == 0 || h > heights[stk.top()])
            {
                stk.push(i);
                continue;
            }
            
            int top = stk.top();
            stk.pop();
            
            int lp = stk.size() == 0 ? 0 : stk.top() + 1;
            int rp = i - 1;
            ans = max(ans, heights[top] * (rp - lp + 1));
            i--;
        }
        return ans;
    }
};
