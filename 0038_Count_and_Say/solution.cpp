class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        else if (n == 2)
            return "11";
        string s = "11";
        stringstream ss;
        for (int i = 3; i <= n; i++)
        {
            string next = "";
            int sz = s.size();
            int ptr = 0;
            int cnt = 0;
            while (ptr < sz)
            {
                if (ptr == 0)
                {
                    cnt++;
                    ptr++;
                    continue;
                }
                if (s[ptr] == s[ptr - 1])
                {
                    cnt++;
                    ptr++;
                }
                else
                {
                    ss.str("");
                    ss.clear();
                    ss << cnt;
                    string t;
                    ss >> t;
                    next += t;
                    next += s[ptr - 1];
                    cnt = 1;
                    ptr++;
                }
            }
            if (cnt != 0)
            {
                ss.str("");
                ss.clear();
                ss << cnt;
                string t;
                ss >> t;
                next += t;
                next += s[ptr - 1];
            }
            s = next;
        }
        return s;
    }
};
