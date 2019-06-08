class Solution {
public:
    
    long long** matrix;
    int m, n;
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        
        if (m == 1 && n == 1 && obstacleGrid[0][0] == 1)
            return 0;
        
        matrix = new long long*[m + 1];
        for (int i = 0; i < m + 1; i++)
        {
            matrix[i] = new long long[n + 1];
            fill_n(matrix[i], n + 1, 0);
        }
        
        
        matrix[m - 1][n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if ((i == m - 1 && j == n - 1) || obstacleGrid[i][j] == 1)
                    continue;
                if (i + 1 >= m || obstacleGrid[i + 1][j] == 0)
                    matrix[i][j] += matrix[i + 1][j];
                if (j + 1 >= n || obstacleGrid[i][j + 1] == 0)
                    matrix[i][j] += matrix[i][j + 1];
            }
        }
        
        return matrix[0][0];
    }
};
