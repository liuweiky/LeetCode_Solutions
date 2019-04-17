class Solution {
public:
    
    vector<vector<int>> ans;
    
    void dfs(int idx, int sum, vector<int>& v, vector<int>& candidates, int& target)
    {
        if (sum == target)
        {
            ans.push_back(v);
            return;
        }
        if (sum > target)
            return;
        
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i != idx && candidates[i] == candidates[i - 1])
                continue;
            v.push_back(candidates[i]);
            dfs(i + 1, sum + candidates[i], v, candidates, target);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(0, 0, v, candidates, target);
        return ans;
    }
};
