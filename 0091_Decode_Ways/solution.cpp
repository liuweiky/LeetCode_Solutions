class Solution {
public:
    
    long long* dp;
    
    int numDecodings(string s) {
        int sz = s.size();
        dp = new long long[sz + 1];
        
        if (s.size() == 0 || s[0] == '0')
            return 0;
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 1; i < sz; i++)
        {
            stringstream ss;
            ss << s.substr(i - 1, 2);
            int t;
            ss >> t;
            
            if (s[i - 1] != '0' && t >= 1 && t <= 26)
            {
                if (s[i] != '0')
                    dp[i + 1] = dp[i] + dp[i - 1];
                else
                    dp[i + 1] = dp[i - 1];
            }
            else if (s[i] == '0')
                dp[i + 1] = 0;
            else
                dp[i + 1] = dp[i];
        }
        
        return dp[s.size()];
    }
};
