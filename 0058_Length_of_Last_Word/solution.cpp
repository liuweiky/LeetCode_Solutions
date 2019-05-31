class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0)
            return 0;
        int endp = s.size() - 1;
        while (endp >= 0 && s[endp] == ' ')
            endp--;
        if (endp < 0)
            return 0;
        int startp = endp;
        while (startp >= 0 && s[startp] != ' ')
            startp--;
        return endp - startp;
    }
};
