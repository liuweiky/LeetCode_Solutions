class Solution {
public:
    bool isPalindrome(int x) {
        int digit[512];
        int p = 0;
        if (x == 0)
            return true;
        if (x < 0)
            return false;
        while (x != 0)
        {
            digit[p++] = x % 10;
            x /= 10;
        }
        for (int i = 0; i < p / 2; i++)
            if (digit[i] != digit[p - 1 - i])
                return false;
        return true;
    }
};
