class Solution {
public:
    
    vector<string> strs;
    
    bool check_val(string s)
    {
        if (s.size() > 3 || s.size() == 0)
            return false;
        
        if (s.size() == 2 && (s[0] == '0' || s == "00"))
            return false;
            
        if (s.size() == 3 && (s[0] == '0' || (s[0] == 0 && s[1] == 0) || s == "000"))
            return false;
        
        stringstream ss;
        ss << s;
        int t;
        ss >> t;
        if (!(t >= 0 && t <= 255))
            return false;
        return true;
    }
    
    void dfs(string& str, int pos, vector<int>& ans)
    {
        if (ans.size() == 3)
        {
            string tmp = str.substr(ans.back() + 1);
            if (!check_val(tmp))
                return;
            string a = str;
            for (int i = 0; i < 3; i++)
                a.insert(ans[i] + 1 + i, ".");
            strs.push_back(a);
            return;
        }
        
        
        for (int i = pos; i < str.size() - 1 && i - pos <= 2; i++)
        {
            string tmp = str.substr(pos, i - pos + 1);
            
            if (!check_val(tmp))
                continue;
            ans.push_back(i);
            dfs(str, i + 1, ans);
            ans.pop_back();
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4)
            return strs;
        
        vector<int> t;
        
        dfs(s, 0, t);
        
        return strs;
    }
};
