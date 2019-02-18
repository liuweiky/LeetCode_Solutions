class Solution {
public:
    string syms[4][2] = 
    {
        {"I", "V"},
        {"X", "L"},
        {"C", "D"},
        {"M", ""}
    };
    
    string ans[16];
    
    string intToRoman(int num) {
        int p = 0;
        while (num)
        {
            int digit = num % 10;
            string psym = "";
            
            if (digit <= 3)
            {
                for (int i = 0; i < digit; i++)
                    psym += syms[p][0];
            }
            else if (digit == 4)
            {
                psym += syms[p][0];
                psym += syms[p][1];
            }
            else if (digit == 5)
                psym = syms[p][1];
            else if (digit <= 8)
            {
                psym = syms[p][1];
                for (int i = 0; i < digit - 5; i++)
                    psym += syms[p][0];
            }
            else
            {
                psym += syms[p][0];
                psym += syms[p + 1][0];
            }
            ans[p++] = psym;
            num /= 10;
        }
        
        string s = "";
        for (int i = p - 1; i >= 0; i--)
            s += ans[i];
        return s;
    }
};
