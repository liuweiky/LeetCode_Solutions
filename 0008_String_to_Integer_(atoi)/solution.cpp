class Solution {
public:
    string trimNum(string str) {
        int s = 0;
        bool neg = false;
        while (s < str.size() && str[s] == ' ')
            s++;
        if (s == str.size())
            return "0";
        if (!(str[s] == '-' || str[s] == '+' || (str[s] <= '9' && str[s] >= '0')))
            return "0";
        if (str[s] == '-')
        {
            s++;
            neg = true;
        }else if (str[s] == '+')
            s++;
        if (s == str.size())
        {
            return "0";
        }
        int t = s;
        while (t < str.size() && str[t] <= '9' && str[t] >= '0')
            t++;
        if (t == s)
            return "0";
        string ret = str.substr(s, t - s);
        if (neg)
            ret = "-" + ret;
        return ret;
    }
    
    int getNum(string str) {
        bool neg = false;
        int p = 0;
        if (str[0] == '-')
        {
            neg = true;
            p = 1;
        }
        reverse(str.begin() + p, str.end());
        long long power = 1;
        long long num = 0;
        while (p < str.size())
        {
            
            if (neg && -num < INT_MIN)
                return INT_MIN;
            if (!neg && num > INT_MAX)
                return INT_MAX;
            if (p > 10 && (str[p] - '0') > 0)
                return neg ? INT_MIN : INT_MAX;
            num += (str[p++] - '0') * power;
            power *= 10;
        }
        if (neg)
            num = -num;
        if (num > INT_MAX)
            return INT_MAX;
        if (num < INT_MIN)
            return INT_MIN;
        return num;
    }
    
    int myAtoi(string str) {
        return (getNum(trimNum(str)));
    }
};
