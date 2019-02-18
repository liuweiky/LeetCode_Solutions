class Solution {
public:
    map<char, int> mp;
    int romanToInt(string s) {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ans = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (i != s.size() - 1)
            {
                string str = "";
                str += s[i]; str += s[i + 1];
                if (str == "IV") {ans += 4; i++; continue;}
                if (str == "IX") {ans += 9; i++; continue;}
                if (str == "XL") {ans += 40; i++; continue;}
                if (str == "XC") {ans += 90; i++; continue;}
                if (str == "CD") {ans += 400; i++; continue;}
                if (str == "CM") {ans += 900; i++; continue;}
            }
            ans += mp[s[i]];
        }
        return ans;
    }
};
