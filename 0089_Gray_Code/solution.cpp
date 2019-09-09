class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> v;
        v.push_back(0);
        if (n == 0)
            return v;
        
        int d = 0;
        
        while (v.size() != 1 << n)
        {
            int sz = v.size();
            
            for (int i = sz - 1; i >= 0; i--)
                v.push_back(v[i] | 1 << d);
            
            d++;
        }
        
        return v;
    }
};
