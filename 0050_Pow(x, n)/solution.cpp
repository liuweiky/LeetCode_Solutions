class Solution {
public:
    
    double powit(double x, long long n)
    {
        if (n == 0)
            return 1.0;
        
        double res = powit(x, n / 2);
        res *= res;
        if (n % 2 == 1)
            res *= x;
        return res;
    }
    
    double myPow(double x, int n) {
        if (n >= 0)
            return powit(x, n);
        else
            return powit(1 / x, -(long long)n);
    }
};
