class Solution {
public:
    
    string trim_slash(string path)
    {
        int pos = path.find("//");
        
        while (pos != string::npos)
        {
            path = path.replace(pos, 2, "/");
            pos = path.find("//");
        }
        if (path[path.length() - 1] == '/')
            path = path.substr(0, path.length() - 1);
        return path;
    }
    
    vector<string> get_seq(string path)
    {
        string tmp = "";
        vector<string> ret;
        int ptr = 1;
        while (ptr < path.length())
        {
            if (path[ptr] == '/' && tmp != "")
            {
                ret.push_back(tmp);
                tmp = "";
            }
            else
            {
                tmp += path[ptr];
            }
            
            ptr++;
        }
        
        if (tmp != "")
            ret.push_back(tmp);
        return ret;
    }
    
    string simplifyPath(string path) {
        stack<string> path_stack;
        vector<string> seq = get_seq(trim_slash(path));
        
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == "..")
            {
                if (!path_stack.empty())
                    path_stack.pop();
            }
            else if (seq[i] != ".")
                path_stack.push(seq[i]);
        }
        
        if (path_stack.empty())
            return "/";
            
        vector<string> tmp;
        string ans = "";
        while (!path_stack.empty())
        {
            string s = path_stack.top();
            path_stack.pop();
            tmp.push_back(s);
        }
        
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            ans += "/";
            ans += tmp[i];
        }
        
        return ans;
    }
};
