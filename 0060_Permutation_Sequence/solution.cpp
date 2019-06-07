class Solution {
public:
    
    int get_fact(int k)
    {
        int ret = 1;
        for (int i = 1; i <= k; i++)
            ret *= i;
        return ret;
    }
    
    string getPermutation(int n, int k) {
        k--;
        string ans = "";
        
        vector<int> numbers;
        
        for (int i = 0; i < n; i++)
            numbers.push_back(i + 1);
        
        for (int i = 1; i <= n; i++)
        {
            int f = get_fact(n - i);
            ans += numbers[k / f] + '0';
            numbers.erase(numbers.begin() + k / f);
            k %= f;
        }
        
        return ans;
    }
};
