class Solution {
public:
    
    string ww;
    vector<vector<char>> bb;
    bool ans;
    bool** vis;
    int m, n;
    
    void dfs(int x, int y, string& str)
    {
        if (ans)
            return;
        if (ww.find(str) != 0)
            return;
        
        if (x > 0 && !vis[x - 1][y])
        {
            str += bb[x - 1][y];
            vis[x - 1][y] = true;
            dfs(x - 1, y, str);
            
            vis[x - 1][y] = false;
            str = str.substr(0, str.size() - 1);
        }
        if (y > 0 && !vis[x][y - 1])
        {
            str += bb[x][y - 1];
            vis[x][y - 1] = true;
            dfs(x, y - 1, str);
            
            vis[x][y - 1] = false;
            str = str.substr(0, str.size() - 1);
        }
        if (x < m - 1 && !vis[x + 1][y])
        {
            str += bb[x + 1][y];
            vis[x + 1][y] = true;
            dfs(x + 1, y, str);
            
            vis[x + 1][y] = false;
            str = str.substr(0, str.size() - 1);
        }
        if (y < n - 1 && !vis[x][y + 1])
        {
            str += bb[x][y + 1];
            vis[x][y + 1] = true;
            dfs(x, y + 1, str);
            
            vis[x][y + 1] = false;
            str = str.substr(0, str.size() - 1);
        }
        
        if (str == ww)
            ans = true;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        ans = false;
        bb = board;
        ww = word;
        m = board.size();
        if (m == 0)
            return false;
        n = board[0].size();
        if (n == 0)
            return false;
        
        vis = new bool*[m];
        for (int i = 0; i < m; i++)
        {
            vis[i] = new bool[n];
            fill_n(vis[i], n, false);
        }
        
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vis[i][j] = true;
                string s = "";
                s += bb[i][j];
                dfs(i, j, s);
                vis[i][j] = false;
            }
        }
        
        return ans;
    }
};
