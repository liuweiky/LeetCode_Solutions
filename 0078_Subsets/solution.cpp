class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> n;
    int total;
    
    void dfs(int ptr, vector<int>& v)
    {
        if (ptr == total)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(n[ptr++]);
        dfs(ptr, v);
        v.pop_back();
        dfs(ptr, v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums;
        total = nums.size();
        vector<int> tmp;
        dfs(0, tmp);
        return ans;
    }
};
