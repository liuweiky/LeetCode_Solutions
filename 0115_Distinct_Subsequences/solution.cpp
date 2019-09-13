class Solution {
public:
    
    long long** dp;
    
    int numDistinct(string s, string t) {
        
        int ss = s.size();
        int st = t.size();
        
        if (ss < st)
            return 0;
        
        dp = new long long*[ss + 1];
        
        for (int i = 0; i <= ss; i++)
        {
            dp[i] = new long long[st + 1];
            fill_n(dp[i], st + 1, 0);
            dp[i][0] = 1;
        }
        
        string tmp = " ";
        s = tmp + s;
        t = tmp + t;
        
        for (int i = 1; i <= ss; i++)
        {
            for (int j = 1; j <= st; j++)
            {
                if (s[i] == t[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[ss][st];
    }
};
