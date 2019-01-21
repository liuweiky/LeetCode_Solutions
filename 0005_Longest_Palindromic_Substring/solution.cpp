class Solution {
public:
    int is_palindromic[1024][1024];
    string longestPalindrome(string s) {
        for (int i = 0; i < 1024; i++)
        {
            for (int j = i; j < 1024; j++)
            {
                if (i == j || (j - i == 1 && s[i] == s[j]))
                {
                    is_palindromic[i][j] = 1;
                } else
                {
                    is_palindromic[i][j] = 0;
                }
            }
        }
        string ans = s.substr(0, 1);
        for (int k = 1; k < s.size(); k++)
        {
            for (int i = 0; i < s.size() - k; i++)
            {
                if (k != 1)
                    is_palindromic[i][i + k] = is_palindromic[i + 1][i + k - 1] && s[i] == s[i + k]  ? 1 : 0;
                if (is_palindromic[i][i + k] && ans.size() < k + 1)
                {
                    ans = s.substr(i, k + 1);
                }
            }
        }
        return ans;
    }
};
