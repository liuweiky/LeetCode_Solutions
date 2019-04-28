class Solution {
public:
    
    bool* vis;
    int sz;
    vector<vector<int>> ans;
    
    void dfs(vector<int>& nums, vector<int>& vec)
    {
        if (vec.size() == sz)
        {
            ans.push_back(vec);
            return;
        }
        
        for (int i = 0; i < sz; i++)
        {
            if (!vis[i])
            {
                vec.push_back(nums[i]);
                vis[i] = true;
                dfs(nums, vec);
                vis[i] = false;
                vec.pop_back();
                while (i + 1 < sz && nums[i] == nums[i + 1])
                    i++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        sz = nums.size();
        vis = new bool[sz];
        fill_n(vis, sz, false);
        vector<int> v;
        dfs(nums, v);
        return ans;
    }
};
