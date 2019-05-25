class Solution {
public:
    
    bool** vis;
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return vector<int>();
        vis = new bool*[matrix.size()];
        for (int i = 0; i < matrix.size(); i++)
            vis[i] = new bool[matrix[i].size()];
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                vis[i][j] = false;
        
        int sz =  row * col;
        
        vector<int> ans;
        int x = 0, y = 0, dir = 1;
        
        while (ans.size() != sz)
        {
            ans.push_back(matrix[x][y]);
            vis[x][y] = true;
            if (dir == 1)   // right
            {
                y++;
                if (y == col || vis[x][y])
                {
                    y--;
                    x++;
                    dir = 2;
                }
            }
            else if (dir == 2)  // down
            {
                x++;
                if (x == row || vis[x][y])
                {
                    x--;
                    y--;
                    dir = 3;
                }
            }
            else if (dir == 3)  // left
            {
                y--;
                if (y < 0 || vis[x][y])
                {
                    y++;
                    x--;
                    dir = 4;
                }
            }
            else    // up
            {
                x--;
                if (x < 0 || vis[x][y])
                {
                    x++;
                    y++;
                    dir = 1;
                }
            }
        }
        
        return ans;
        
    }
};
