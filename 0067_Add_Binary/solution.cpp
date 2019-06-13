class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size())
            swap(a, b);
        int carry = 0;
        
        for (int i = 0; i < b.size(); i++)
        {
            int t = b[i] - '0' + carry + a[i] - '0';
            a[i] = t % 2 + '0';
            carry = t / 2;
        }
        
        for (int i = b.size(); i < a.size(); i++)
        {
            int t = carry + a[i] - '0';
            a[i] = t % 2 + '0';
            carry = t / 2;
        }
        
        reverse(a.begin(), a.end());
        
        if (carry)
            a.insert(a.begin(), '1');
        return a;
    }
};
