class Solution {
public:
    
    string add(string s1, string s2)
    {
        string res = "";
        
        int carry = 0;
        
        if (s1.size() < s2.size())
            swap(s1, s2);
        
        int min_sz = s2.size();
        
        for (int i = 0; i < min_sz; i++)
        {
            int t1 = s1[i] - '0';
            int t2 = s2[i] - '0';
            int t = t1 + t2 + carry;
            res += (t % 10) + '0';
            carry = t / 10;
        }
        
        for (int i = min_sz; i < s1.size(); i++)
        {
            int t1 = s1[i] - '0';
            int t = t1 + carry;
            res += t % 10 + '0';
            carry = t / 10;
        }
        
        if (carry)
            res += carry + '0';
        
        return res;
    }
    
    string mul_digit(string s1, int d)
    {
        int carry = 0;
        string res = "";
        
        for (int i = 0; i < s1.size(); i++)
        {
            int t1 = s1[i] - '0';
            int t = t1 * d + carry;
            res += t % 10 + '0';
            carry = t / 10;
        }
        
        if (carry)
            res += carry + '0';
        
        return res;
    }
    
    string mul(string s1, string s2)
    {
        if (s1.size() < s2.size())
            swap(s1, s2);
        
        string res = "";
        
        for (int i = s2.size() - 1; i >= 0; i--)
        {
            string t = mul_digit(s1, s2[i] - '0');
            //cout << t << endl;
            res.insert(res.begin(), '0');
            //cout << res << endl;
            res = add(res, t);
            //cout << res << endl;
        }
        return res;
    }
    
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = mul(num1, num2);
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
