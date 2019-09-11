class Solution {
public:
    
    int** mem;
    
    string ss1, ss2, ss3;
    
    bool check(int ptr1, int ptr2, int ptr3)
    {
        if (mem[ptr1][ptr2] != 0)
            return mem[ptr1][ptr2] == 1 ? true : false;
        while (ptr3 < ss3.size())
        {
            
            if (ptr1 < ss1.size() && ss1[ptr1] == ss3[ptr3] && ptr2 < ss2.size() && ss2[ptr2] == ss3[ptr3])
            {
                if (check(ptr1 + 1, ptr2, ptr3 + 1))
                {
                    mem[ptr1][ptr2] = 1;
                    return true;
                }
                else if (check(ptr1, ptr2 + 1, ptr3 + 1))
                {
                    mem[ptr1][ptr2] = 1;
                    return true;
                }
                mem[ptr1][ptr2] = 2;
                return false;
            }
            
            
            if (ptr1 < ss1.size() && ss1[ptr1] == ss3[ptr3])
            {
                ptr1++;
                ptr3++;
                continue;
            }
            
            if (ptr2 < ss2.size() && ss2[ptr2] == ss3[ptr3])
            {
                ptr2++;
                ptr3++;
                continue;
            }
            mem[ptr1][ptr2] = 2;
            return false;
        }
        mem[ptr1][ptr2] = 1;
        return true;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() + s2.size() != s3.size())
            return false;
        
        mem = new int*[s1.size() + 1];
        
        for (int i = 0; i < s1.size() + 1; i++)
        {
            mem[i] = new int[s2.size() + 1];
            fill_n(mem[i], s2.size() + 1, 0);
        }
        
        ss1 = s1;
        ss2 = s2;
        ss3 = s3;
        
        return check(0, 0, 0);
    }
};
