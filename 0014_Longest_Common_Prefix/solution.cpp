class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        if (strs.size() == 0)
            return s;
        int i = 0, len = strs.size(), len0 = strs[0].size();
        bool flag = true;
        string c = "";
        while (flag)
        {
            s += c;
            if (i >= len0)
                break;
            c = strs[0][i];
            for (int j = 1; j < len; j++)
                if (i >= strs[j].size() || c != strs[j].substr(i, 1))
                {
                    flag = false;
                    break;
                }
            i++;
        }
        return s;
    }
};
