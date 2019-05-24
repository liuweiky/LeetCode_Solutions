class Solution {
public:
    
    int* chess_board;
    bool* mp;
    int size_n;
    
    vector<vector<string>> ans;
    
    bool check(int k)
    {
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if (abs(i - j) == abs(chess_board[i] - chess_board[j]))
                    return false;
        return true;
    }
    
    void dfs(int t)
    {
        if (t == size_n)
        {
            vector<string> a;
            for (int i = 0; i < size_n; i++)
            {
                string str = "";
                for (int j = 0; j < size_n; j++)
                    str += ".";
                str[chess_board[i]] = 'Q';
                a.push_back(str);
            }
            ans.push_back(a);
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
    
    vector<vector<string>> solveNQueens(int n) {
        size_n = n;
        chess_board = new int[n];
        mp = new bool[n];
        fill_n(mp, n, false);
        
        dfs(0);
        return ans;
    }
};
