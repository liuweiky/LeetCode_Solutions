class Solution {
public:
    
    int** matrix;
    
    int uniquePaths(int m, int n) {
        matrix = new int*[m + 1];
        for (int i = 0; i < m + 1; i++)
        {
            matrix[i] = new int[n + 1];
            fill_n(matrix[i], n + 1, 0);
        }
        
        
        
        matrix[m - 1][n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        
        return matrix[0][0];
    }
};
