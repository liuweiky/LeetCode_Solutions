class Solution {
public:
    
    vector<vector<int>> ans;
    
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return ans;
        
        vector<int> tmp;
        tmp.push_back(1);
        
        ans.push_back(tmp);
        
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> v(i, 0);
            v[0] = 1;
            
            for (int j = 1; j <= (i - 1) / 2; j++)
                v[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            
            for (int j = i - 1; j >= (i - 1) / 2; j--)
                v[j] = v[i - 1 - j];
            
            ans.push_back(v);
        }
        
        return ans;
    }
};
