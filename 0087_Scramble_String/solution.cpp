class Solution {
public:
    
    int mp[256];
    
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        
        if (s1.size() != s2.size())
            return false;
        
        fill_n(mp, 256, 0);
        
        for (int i = 0; i < s1.size(); i++)
            mp[s1[i]]++;
        
        bool flag = true;
        
        for (int i = 0; i < s1.size(); i++)
        {
            if (mp[s2[i]] <= 0)
            {
                flag = false;
                break;
            }
            mp[s2[i]]--;
        }
        
        if (!flag)
            return false;
        
        for (int len = 1; len <= s1.size() - 1; len++)
        {
            if (isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len, s1.size() - len), s2.substr(len, s2.size() - len)))
                return true;
            if (isScramble(s1.substr(0, len), s2.substr(s2.size() - len, len)) && isScramble(s1.substr(len, s1.size() - len), s2.substr(0, s2.size() - len)))
                return true;
        }
        
        return false;
    }
};
