class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        
        while (true)
        {
            while (i < s.size() && !isalpha(s[i]) && !isdigit(s[i]))
                i++;
            while (j >= 0 && !isalpha(s[j]) && !isdigit(s[j]))
                j--;
            
            if (i >= j)
                return true;
            
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
    }
};
