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
            v.push_back(candidates[i]);
            dfs(i, sum + candidates[i], v, candidates, target);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        dfs(0, 0, v, candidates, target);
        return ans;
    }
};
