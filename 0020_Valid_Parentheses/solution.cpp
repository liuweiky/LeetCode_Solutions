class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && stk.size() == 0)
                return false;
            if (s[i] == '(')
                stk.push('(');
            else if (s[i] == ')')
            {
                if (stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else if (s[i] == '{')
                stk.push('{');
            else if (s[i] == '}')
            {
                if (stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
            else if (s[i] == '[')
                stk.push('[');
            else if (s[i] == ']')
            {
                if (stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
        }
        if (stk.size() == 0)
            return true;
        else
            return false;
    }
};
