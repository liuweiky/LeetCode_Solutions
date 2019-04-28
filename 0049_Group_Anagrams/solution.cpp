class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp.find(s) == mp.end())
            {
                vector<string> v;
                mp[s] = v;
            }
            mp[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
        for (map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};
