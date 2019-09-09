class Solution {
public:
    
    vector<vector<int>> ans;
    
    void dfs(vector<int>& v, int pos, vector<int>& nums)
    {
        ans.push_back(v);
        
        for (int i = pos; i < nums.size();)
        {
            v.push_back(nums[i]);
            dfs(v, i + 1, nums);
            v.pop_back();
            
            i++;
            
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> tmp;
        
        dfs(tmp, 0, nums);
        return ans;
    }
};
