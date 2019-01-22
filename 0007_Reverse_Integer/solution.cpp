class Solution {
public:
    int reverse(int x) {
        int digit[512];
        int neg = 1;
        long long xt = x;
        if (xt < 0)
        {
            neg = -1;
            xt = -xt;
        }
        long long rev = 0;
        int p = 0;
        while (xt != 0)
        {
            digit[p++] = xt % 10;
            xt /= 10;
        }
        long long power = 1;
        for (int i = p - 1; i >= 0; i--)
        {
            rev += digit[i] * power;
            power *= 10;
        }
        if (rev > INT_MAX)    // Overflow
            return 0;
        return neg * rev;
    }
};
