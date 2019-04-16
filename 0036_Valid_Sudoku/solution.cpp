class Solution {
public:
    bool mp[10];
    
    bool check_row(int row, vector<vector<char>>& board)
    {
        fill_n(mp, 10, false);
        for (int i = 0; i < 9; i++)
        {
            if (isdigit(board[row][i]))
            {
                if (mp[board[row][i] - '0'])
                    return false;
                mp[board[row][i] - '0'] = true;
            }
        }
        return true;
    }
    
    bool check_col(int col, vector<vector<char>>& board)
    {
        fill_n(mp, 10, false);
        for (int i = 0; i < 9; i++)
        {
            if (isdigit(board[i][col]))
            {
                if (mp[board[i][col] - '0'])
                    return false;
                mp[board[i][col] - '0'] = true;
            }
        }
        return true;
    }
    
    bool check_9(int s, int t, vector<vector<char>>& board)
    {
        fill_n(mp, 10, false);
        for (int i = s * 3; i < (s + 1) * 3; i++)
        {
            for (int j = t * 3; j < (t + 1) * 3; j++)
            {
                if (isdigit(board[i][j]))
                {
                    if (mp[board[i][j] - '0'])
                        return false;
                    mp[board[i][j] - '0'] = true;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
        {
            if (!check_row(i, board))
                return false;
            if (!check_col(i, board))
                return false;
        }
        
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (!check_9(i, j, board))
                    return false;
        return true;
    }
};
