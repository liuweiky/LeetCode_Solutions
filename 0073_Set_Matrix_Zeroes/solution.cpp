class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0)
            return;
        bool* row_to_fill = new bool[m];
        bool* col_to_fill = new bool[n];
        fill_n(row_to_fill, m, false);
        fill_n(col_to_fill, n, false);
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                row_to_fill[i] |= matrix[i][j] == 0;
                col_to_fill[j] |= matrix[i][j] == 0;
            }
        
        for (int i = 0; i < m; i++)
        {
            if (row_to_fill[i])
            {
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if (col_to_fill[i])
            {
                for (int j = 0; j < m; j++)
                    matrix[j][i] = 0;
            }
        }
        
        return;
    }
};
