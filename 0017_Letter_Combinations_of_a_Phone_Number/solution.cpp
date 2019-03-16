class Solution {
public:
    
    vector<string> ans;
    map<char, string> mp;
    
    void dfs(string digits, string comb)
    {
        if (digits.size() == 0)
        {
            ans.push_back(comb);
            return;
        }
        
        char c = digits[0];
        digits = digits.substr(1, digits.size() - 1);
        
        int sz = mp[c].size();
        
        for (int i = 0; i < sz; i++)
            dfs(digits, comb + mp[c][i]);
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ans;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        dfs(digits, "");
        return ans;
    }
};
