class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(vector<int> (n, 0));
        
        int dir = 1;
        int x, y;
        x = y = 0;
        
        int n2 = n * n;
        
        for (int i = 1; i <= n2; i++)
        {
            ans[x][y] = i;
            if (dir == 1)
            {
                if (y + 1 == n || ans[x][y + 1] != 0)
                {
                    x++;
                    dir = 2;
                }
                else
                    y++;
            }
            else if (dir == 2)
            {
                if (x + 1 == n || ans[x + 1][y] != 0)
                {
                    y--;
                    dir = 3;
                }
                else
                    x++;
            }
            else if (dir == 3)
            {
                if (y - 1 < 0 || ans[x][y - 1] != 0)
                {
                    x--;
                    dir = 4;
                }
                else
                    y--;
            }
            else
            {
                if (x - 1 < 0 || ans[x - 1][y] != 0)
                {
                    y++;
                    dir = 1;
                }
                else
                    x--;
            }
        }
        
        return ans;
    }
};
