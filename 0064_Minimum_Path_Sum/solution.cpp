class Solution {
public:
    
    int** min_sum;
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        min_sum = new int*[m + 1];
        
        for (int i = 0; i <= m; i++)
        {
            min_sum[i] = new int[n + 1];
            fill_n(min_sum[i], n + 1, INT_MAX);
        }
        
        min_sum[m - 1][n - 1] = grid[m - 1][n - 1];
        
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                min_sum[i][j] = min(min_sum[i + 1][j], min_sum[i][j + 1]) + grid[i][j];
            }
        }
        return min_sum[0][0];
    }
};
