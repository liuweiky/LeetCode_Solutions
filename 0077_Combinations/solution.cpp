class Solution {
public:
    
    vector<vector<int>> ans;
    
    int nn, kk;
    
    void dfs(vector<int>& t)
    {
        if (t.size() == kk)
        {
            ans.push_back(t);
            return;
        }
        
        if (t.size() != 0 && t[t.size() - 1] + kk - t.size() > nn)
            return;
        
        for (int i = t.size() == 0 ? 1 : t[t.size() - 1] + 1; i <= nn; i++)
        {
            t.push_back(i);
            dfs(t);
            t.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        nn = n;
        kk = k;
        vector<int> tmp;
        dfs(tmp);
        return ans;
    }
};
