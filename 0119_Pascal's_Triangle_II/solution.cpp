class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);
        
        if (rowIndex == 0)
            return prev;
        
        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> ans(i + 1, 0);
            
            ans[0] = 1;
            
            for (int j = 1; j <= i / 2; j++)
                ans[j] = prev[j - 1] + prev[j];
            
            for (int j = i; j >= i / 2; j--)
                ans[j] = ans[i - j];
            
            prev = ans;
        }
        
        return prev;
    }
};
