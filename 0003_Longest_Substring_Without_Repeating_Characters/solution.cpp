class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        int len;
        int* st = new int[s.length()];
        fill_n(st, s.length(), 1);
        len = 1;
        for (int i = 1; i < s.length(); i++)
        {
            int l = st[i - 1];
            int j = i - 1;
            while (l != 0)
            {
                if (s[i] == s[j])
                {
                    st[i] = i - j;
                    if (st[i] > len)
                        len = st[i];
                    break;
                }
                j--;
                l--;
            }
            if (l == 0)
            {
                st[i] = st[i - 1] + 1;
                if (st[i] > len)
                    len = st[i];
            }
        }
        delete[] st;
        return len;
    }
};
