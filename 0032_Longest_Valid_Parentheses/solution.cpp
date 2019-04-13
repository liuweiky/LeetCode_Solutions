class Solution {
public:
    
    bool* is_val;
    int* dp;
    
    int longestValidParentheses(string s) {
        int sz = s.size();
        
        if (sz == 0)
            return 0;
        
        is_val = new bool[sz];
        dp = new int[sz];
        
        fill_n(is_val, sz, false);
        stack<pair<int, char> > stk;
        
        int ptr = 0;
        
        while (ptr < sz)
        {
            while (ptr < sz && stk.size() > 0 && stk.top().second == '(' && s[ptr] == ')')
            {
                pair<int, char> p = stk.top();
                stk.pop();
                is_val[ptr] = is_val[p.first] = true;
                ptr++;
            }
            if (ptr == sz)
                break;
            stk.push(make_pair(ptr, s[ptr]));
            ptr++;
        }
        
        int ans;
        
        dp[0] = is_val[0] ? 1 : 0;
        
        ans = dp[0];
        
        for (int i = 1; i < sz; i++)
        {
            if (is_val[i])
            {
                dp[i] = dp[i - 1] + 1;
                ans = max(ans, dp[i]);
            }
            else
                dp[i] = 0;
        }
        
        return ans;
    }
};
