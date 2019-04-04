class Solution {
public:
    
    vector<string> ans;
    
    bool check(string s, int type)
    {
        stack<char> stk;
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '(')
                stk.push('(');
            else
            {
                if (stk.size() > 0 && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
        }
        
        if (type == 0)
            return true;
        
        if (stk.size() == 0)
            return true;
        else
            return false;
    }
    
    void dfs(string s, int n, int left_cnt, int right_cnt)
    {
        if (s.size() == 2 * n)
        {
            if (check(s, 1))
                ans.push_back(s);
            return;
        }
        if (!check(s, 0))
            return;
        if (left_cnt < n)
            dfs(s + "(", n, left_cnt + 1, right_cnt);
        if (right_cnt < n)
            dfs(s + ")", n, left_cnt, right_cnt + 1);
        
    }
    
    vector<string> generateParenthesis(int n) {
        dfs("(", n, 1, 0);
        return ans;
    }
};
