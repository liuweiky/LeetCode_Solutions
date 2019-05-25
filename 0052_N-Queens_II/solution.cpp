class Solution {
public:
    
    int* chess_board;
    bool* mp;
    int size_n;
    
    int ans;
    
    bool check(int k)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
                if (abs(i - j) == abs(chess_board[i] - chess_board[j]))
                    return false;
        }
        return true;
    }
    
    void dfs(int t)
    {
        if (t == size_n)
        {
            ans++;
            return;
        }
        
        for (int i = 0; i < size_n; i++)
        {
            if (!mp[i])
            {
                chess_board[t] = i;
                if (!check(t + 1))
                    continue;
                mp[i] = true;
                dfs(t + 1);
                mp[i] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        size_n = n;
        chess_board = new int[n];
        mp = new bool[n];
        fill_n(mp, n, false);
        
        dfs(0);
        return ans;
    }
};
