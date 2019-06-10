class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (i == digits.size() - 1)
            {
                int t = digits[i] + 1;
                if (t < 10)
                {
                    digits[i] = t;
                    return digits;
                }
                carry = 1;
                digits[i] = t % 10;
                continue;
            }
            if (carry == 0)
                return digits;
            int t = digits[i] + carry;
            digits[i] = t % 10;
            carry = t / 10;
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
