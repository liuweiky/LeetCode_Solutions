class Solution {
public:
    
    bool solved;
    bool num_used[16][16];
    bool mp[10];
    
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
    
    void print_board(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%c ", board[i][j]);
            putchar('\n');
        }
    }
    
    void dfs(vector<vector<char>>& board, int ptr)
    {
        //printf("%d", ptr);
        //print_board(board);
        if (ptr >= 81)
        {
            solved = true;
            return;
        }
        int x = ptr / 9;
        int y = ptr % 9;
        
        if (isdigit(board[x][y]))
        {
            dfs(board, ptr + 1);
            return;
        }
        
        for (int i = 1; i <= 9; i++)
        {
            if (num_used[x][i])
                continue;
            board[x][y] = i + '0';
            
            if (!(/*check_row(x, board) && */check_col(y, board) && check_9(x / 3, y / 3, board)))
            {
                board[x][y] = '.';
                continue;
            }
            num_used[x][i] = true;
            dfs(board, ptr + 1);
            if (solved)
                return;
            num_used[x][i] = false;
            board[x][y] = '.';
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++)
        {
            for (int n = 1; n <= 9; n++)
                num_used[i][n] = false;
            for (int j = 0; j < 9; j++)
            {
                if (isdigit(board[i][j]))
                    num_used[i][board[i][j] - '0'] = true;
            }
        }
        solved = false;
        dfs(board, 0);
    }
};
