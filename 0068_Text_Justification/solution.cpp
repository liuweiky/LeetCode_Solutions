class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int ptr = 0;
        
        vector<string> ans;
        int len = 0;
        vector<string> tmp;
        
        while (ptr < words.size())
        {
            if (len == 0)
            {
                len = words[ptr].size();
                tmp.push_back(words[ptr]);
                ptr++;
            }
            else if (len + 1 + words[ptr].size() <= maxWidth)
            {
                len += words[ptr].size();
                len++;
                tmp.push_back(words[ptr]);
                ptr++;
            }
            else
            {
                int tmplen = 0;
                for (int i = 0; i < tmp.size(); i++)
                    tmplen += tmp[i].size();
                int avg, mod;
                if (tmp.size() == 1)
                {
                    avg = 0;
                    mod = 0;
                }
                else
                {
                    avg = (maxWidth - tmplen) / (tmp.size() - 1);
                    mod = (maxWidth - tmplen) % (tmp.size() - 1);
                }
                string s = "";
                string ss = "";
                
                for (int i = 0; i < avg; i++)
                    ss += " ";
                
                for (int i = 0; i < tmp.size(); i++)
                {
                    if (i != 0)
                    {
                        s += ss;
                        if (i <= mod)
                            s += " ";
                    }
                    s += tmp[i];
                }
                
                while (tmp.size() == 1 && s.size() < maxWidth)
                    s += " ";
                
                ans.push_back(s);
                
                len = 0;
                tmp.clear();
            }
        }
        
        string s = "";
        
        for (int i = 0; i < tmp.size(); i++)
        {
            if (i != 0)
                s += " ";
            s += tmp[i];
        }
        
        while (s.size() < maxWidth)
            s += " ";
        
        ans.push_back(s);
        
        return ans;
        
    }
};
